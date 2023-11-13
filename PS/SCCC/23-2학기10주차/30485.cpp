#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<deque>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int mx=100005;

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> iii;

vector<int> tree[mx];
int ans[mx], dis[mx];
int n;

void dfs(int node, int mom){
  deque<iii> Q;
  Q.push_back({node, mom, 0});
  int nd, m, d;
  while(!Q.empty()){
    tie(nd, m, d)=Q.front(); Q.pop_front();
    if(d>dis[node]) break;

    if(nd!=node){
      if(node<nd){
        if(d<dis[node])
          ans[node]=nd;
        else if(d==dis[node])
          ans[node]=min(nd, ans[node]);
        dis[node]=min(d, dis[node]);
      }
      else{
        if(d<dis[nd])
          ans[nd]=node;
        else if(d==dis[nd])
          ans[nd]=min(node, ans[nd]);
        dis[nd]=min(d, dis[nd]);
      }
    }

    for(int nxt: tree[nd]){
      if(nxt!=m)
        Q.push_back({nxt, nd, d+1});

      if(nd<nxt){
        if(dis[nd]>1)
          ans[nd]=nxt;
        else
          ans[nd]=min(nxt, ans[nd]);
        dis[nd]=1;
      }
      else{
        if(dis[nxt]>1)
          ans[nxt]=nd;
        else
          ans[nxt]=min(nd, ans[nxt]);
        dis[nxt]=1;
      }
    }
  }
}



int main(){
  ioset();
  int i, a, b;

  cin>>n;
  fill(ans, ans+mx, n);
  fill(dis, dis+mx, mx);
  for(i=0; i<n-1; i++){
    cin>>a>>b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  for(i=n; i>0; i--){
    dfs(i, 0);
  }
  for(i=1; i<=n; i++)
    cout<<ans[i]<<' ';
  cout<<'\n';
  /*
  for(i=1; i<=n; i++)
    cout<<dis[i]<<' ';
  */
}
