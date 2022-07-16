//17412
#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#include<deque>
#define endl '\n'
#define ioset() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define inf (1000000000)
using namespace std;
typedef tuple<int, int, int> iii;

vector<int> g[405], r[405];
int cap[405][405], flow[405][405];
int visit[405], back[405];
deque<iii> Q;

int abs(int x){
    return x>0?x:-x;
}

int bfs(){
    while(!Q.empty()){
        int prev, now, val; //prev가 음수면 빽도침
        tie(prev, now, val)=Q.front();
        Q.pop_front();
        
        if(now==2){
            back[2]=prev;
            return val;
        }
        if(visit[now]++)
            continue;
        back[now]=prev;
        for(int i: g[now]){
            int p=cap[now][i]-flow[now][i];
            if(p>0)
                Q.push_back({now, i, min(val, p)});
        }
        for(int i: r[now]){
            int p=flow[i][now];
            if(p>0)
                Q.push_back({-now, i, min(val, p)});
        }
    }
    return -1;
}

int main(){
    ioset();
    int n, p, i, x, y, ans=0;
    cin>>n>>p;
    for(i=0; i<p; i++){
        cin>>x>>y;
        if(!cap[x][y]++){
            g[x].push_back(y);
            r[y].push_back(x);
        }
    }
    
    while(1){
        fill(visit, visit+405, 0);
        fill(back, back+405, 0);
        Q.clear();
        Q.push_back({0, 1, inf});
        int val=bfs();
        if (val==-1)
            break;
        ans+=val;
        
        int node=2;
        while(back[node]){
            int x=back[node];
            if(x<0)
                flow[node][-x]-=val;
            else
                flow[x][node]+=val;
            node=abs(x);
        }
    }
    cout<<ans;
}
