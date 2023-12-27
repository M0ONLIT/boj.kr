#testing chatgpt 3.5

import sys
from math import *
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

def changetype(value, *types):
    for i in range(min(len(value), len(types))):
        value[i]=types[i](value[i])
    return value

# 함수 정의
def stock_simulation(N, M, Q, companies, queries):
    cash = M  # 초기 보유 현금
    stocks = {}  # 주식 보유량

    for query in queries:
        menu = query[0]
        if menu == 1:  # 주식 구매
            company = query[1]
            price = companies[company][2]
            quantity = query[2]
            total_cost = price * quantity
            if cash >= total_cost:
                cash -= total_cost
                if company in stocks:
                    stocks[company] += quantity
                else:
                    stocks[company] = quantity

        elif menu == 2:  # 주식 판매
            company = query[1]
            if company in stocks:
                quantity = query[2]
                if quantity >= stocks[company]:
                    cash += stocks[company] * companies[company][2]
                    del stocks[company]
                else:
                    cash += quantity * companies[company][2]
                    stocks[company] -= quantity

        elif menu == 3:  # 주가 상승
            company = query[1]
            increase = query[2]
            companies[company][2] += increase

        elif menu == 4:  # 그룹 주가 상승
            group = int(query[1])
            increase = query[2]
            for company, info in companies.items():
                if info[0] == group:
                    info[2] += increase

        elif menu == 5:  # 그룹 주가 백분율 상승
            group = int(query[1])
            percent = query[2]
            for company, info in companies.items():
                assert type(info[0])==type(group)
                if info[0] == group:
                    increase = (info[2] * percent / 100) // 10 * 10
                    info[2] += int(increase)

        elif menu == 6:  # 현금 출력
            print(cash)

        elif menu == 7:  # 보유 주식 전부 판매 후 총 현금 출력
            total_cash = cash
            for company, quantity in stocks.items():
                total_cash += quantity * companies[company][2]
            print(total_cash)

# 입력 처리
N, M, Q = ints()
companies = {}
for _ in range(N):
    G, H, P = input().split()
    companies[H] = [int(G), H, int(P)]

queries = []
for _ in range(Q):
    query = changetype(input().split(), int, str, int)
    queries.append(query)

# 시뮬레이션 실행
stock_simulation(N, M, Q, companies, queries)
