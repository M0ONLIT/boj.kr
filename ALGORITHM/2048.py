from time import sleep, time
import re
import random
from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from math import inf

##
driver=webdriver.Chrome(r'C:\Users\ab911\Desktop\파이썬\auto\chromedriver')
##크롬 드라이버 경로 설정

driver.get('https://www.flappy-2048.com/')
clk=driver.find_element_by_css_selector('body')

leveling=10 #10픽셀을 1로
def blockhash(block):
    d={(0, 1):0, (0, 3):1, (2, 3):2}
    h=3*d[(block[0][0], block[1][0])]+d[(block[2][0], block[3][0])]
    return h, block[0][1]

class Info:
    def __init__(self):
        self.prev=self.now=0
        self.last=1
        self.block=()
        self.me=0
    def update(self, block, me, num):
        self.block=block
        self.me=me
        self.prev=self.now
        self.now=num

    def ifincreased(self):
        if self.prev<self.now and self.now>1:
            return 2 #증가
        elif self.prev==self.now or self.now==1:
            return 1 #변화X
        else:
            return 0 #감소

class Ai:
    def __init__(self):
        self.gamma=0.99 #할인률
        self.alpha=0.1 #성장률
        self.t=40 #

        self.Rt=[0]*self.t #보상
        self.St=[0]*self.t #상태
        self.Ct=[0]*self.t #선택
        try:
            with open('Q.txt') as file:
                self.generate=int(file.readline())
                self.Q=eval(file.readline()) #Q-learning 머신
        except:
            self.generate=0
            self.Q={} #Q-learning 머신

    def R(self, info): #보상체계
        value=info.ifincreased()
        if value==0: #죽었을 때
            return 0
        elif value==1:
            if info.last==1:
                return 0.005
            return 0.01
        elif value==2: #점수 얻을 때
            return 1


    def action(self, info):
        gamma=self.gamma
        alpha=self.alpha
        Rt=self.Rt
        St=self.St
        Ct=self.Ct
        Q=self.Q #(블럭모양, 앞블럭좌표
        R=self.R
        term=6
        epsilon=20

        Rt.pop(0)
        Rt.append(R(info))
        Sn=(*info.block, info.me, info.last)
        S=St.pop(0)
        St.append(Sn)
        C=Ct.pop(0), #점프했다면 (1,) 아니면 (0,)

        if St[-1]==St[-2]:
            Ct.append(None)
            return 0

        if S!=0 and C!=(None,):
            Q[S+C]=(1-alpha)*Q[S+C]+alpha*sum(Rt[self.t-i-1]*gamma**i for i in range(self.t))

        notjump=Sn+(0,)
        jump=Sn+(1,)
        if Q.get(notjump)==None:
            Q[notjump]=0 #초기화
        if Q.get(jump)==None:
            Q[jump]=0 #초기화

        if info.me<-2:
            Ct.append(0)
            return 0
        elif info.me>20:
            clk.send_keys(Keys.SPACE)
            Ct.append(1)
            return 1

        if random.randint(1, epsilon)==1:
            v=random.randint(0, 1)
            clk.send_keys(Keys.SPACE) if v else None
            Ct.append(v)
            return v

        if Q[notjump]<Q[jump]:
            clk.send_keys(Keys.SPACE)
            Ct.append(1)
            return 1
        else:
            Ct.append(0)
            return 0

ai=Ai()
info=Info()
generate=ai.generate


t=0
prev=0
while 1:
    prev=time()
    html=BeautifulSoup(driver.page_source, 'html.parser')

    soup=html.find_all(class_=re.compile('tile-block-.'))
    block=map(lambda x: re.findall('-?[\d\.]+', x['style']), soup)
    block=list(map(lambda x: (int(float(x[0])//67.5), int(float(x[1])//leveling)), block))
    block.sort(key=lambda x: (x[1], x[0]))
    block=blockhash(block)
    soup=html.find(class_=re.compile('tile-\d+'))
    me=int(float(re.findall('-?[\d\.]+', soup['style'])[0])//leveling)
    num=int(soup.find(class_='tile-inner').text)

    info.update(block, me, num)

    click=ai.action(info)
    info.last=1 if click else min(info.last+1, 40)
    if t==600:
        print(f'{generate+1}세대')
        with open('Q.txt', 'w') as file:
            if info.ifincreased()==0:
                file.write(f'{generate+1}\n')
            else:
                file.write(f'{generate}\n')
            file.write(str(ai.Q))
        generate+=1
        t=0
    t+=1
    sleep(max(0, 0.05+prev-time()))
