#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m, b, ans, fb;

vector<int> graph[200005];
int visit[200005];

int dfs(int node){
  if(visit[node]) return 0;
  visit[node]=1;
  int ans=1; //me
  for(int &i: graph[node]){
    if(i==b) fb++;
    else ans+=dfs(i);
  }
  return ans;
}

int main(){
  ioset();
  int i, j;
  cin>>n>>m;

  for(i=0; i<m; i++){
    int x, y;
    cin>>x>>y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  cin>>b;

  for(i=1; i<=n; i++){
    if(visit[i] || i==b) continue;
    fb=0;
    int p=dfs(i);
    if(fb==1) p++;

    ans=max(ans, p);
  }
  cout<<ans;
}
