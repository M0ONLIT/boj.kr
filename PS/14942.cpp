#include<iostream>
#include<vector>
#define LOG 20
using namespace std;
typedef long long ll;

int ants[100005], mom[100005][LOG];
ll dis[100005][LOG];
vector<pair<int, int>> tree[100005];
int n, visit[100005];

void dfs(int node, int prev, int prev_dis){
    if(visit[node])
        return;
    visit[node]=1;
    mom[node][0]=prev;
    dis[node][0]=prev_dis;
    for(pair<int, int> i: tree[node]){
        dfs(i.first, node, i.second);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin>>n; //1~n번방까지 있다고 함.
    for(int i=1; i<=n; i++)
        cin>>ants[i];
    for(int i=0; i<n-1; i++){
        int x, y, d;
        cin>>x>>y>>d;
        tree[x].push_back({y, d});
        tree[y].push_back({x, d});
    }
    dfs(1, 1, 0);
    
    for(int i=1; i<LOG; i++){
        for(int j=1; j<=n; j++){
            dis[j][i]=dis[j][i-1]+dis[mom[j][i-1]][i-1];
            mom[j][i]=mom[mom[j][i-1]][i-1];
        }
    }
    
    for(int i=1; i<=n; i++){
        int k=ants[i];
        int loc=i;
        for(int j=LOG-1; j>=0; j--){
            if(dis[loc][j]<=k){
                k-=dis[loc][j];
                loc=mom[loc][j];
            }
        }
        cout<<loc<<'\n';
    }
}
