#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m, visit[1005], cnt;
vector<int> f[1005], e[1005];

void dfs(int node){
    if(visit[node]++) return;
    for(int i: f[node]){
        dfs(i);
    }
    for(int i: e[node]){
        for(int j: e[i]){
            dfs(j);
        }
    }
}

int main() {
    ioset();
    int i, j;
    cin>>n>>m;
    for(i=0; i<m; i++){
        char c;
        int x, y;

        cin>>c>>x>>y;
        if(c=='E'){
            e[x].push_back(y);
            e[y].push_back(x);
        }
        else{
            f[x].push_back(y);
            f[y].push_back(x);
        }
    }
    for(i=1; i<=n; i++){
        if(!visit[i]){
            dfs(i);
            cnt++;
        }
    }
    cout<<cnt;
}
