#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mx=3005;

class Point{
public:
  ll x, y, r;
} arr[mx];

ll pow2(ll x){
  return x*x;
}

ll dis(Point p1, Point p2){
  return pow2(p1.x-p2.x)+pow2(p1.y-p2.y);
}

ll n, m, siru, p[mx], ans;
ll visit[mx], start[mx];
//start는 0이어야 시작점이 됨

void dfs1(int node){
  start[node]=1;
  for(int i=1; i<=n; i++){
    if(dis(arr[node], arr[i])<=pow2(arr[node].r)){
      start[i]=1;
    }
  }
}

void dfs2(int node){
  if(visit[node]) return;
  visit[node]=1;

  ans++;
  for(int i=1; i<=n; i++){
    if(dis(arr[node], arr[i])<=pow2(siru) && node!=i){
      dfs2(i);
    }
  }
}

int main(){
  ioset();
  ll i, j, k, x;
  cin>>n>>m;
  for(i=1; i<=n; i++){
    cin>>arr[i].x>>arr[i].y;
    arr[i].r=0;
  }
  for(i=1; i<=m; i++) cin>>p[i];
  cin>>siru;
  for(i=1; i<=m; i++){
    cin>>x;
    arr[p[i]].r=max(x, arr[p[i]].r);
  }
  for(i=1; i<=m; i++){
    dfs1(p[i]);
  }
  for(i=1; i<=n; i++){
    if(!start[i])
      dfs2(i);
  }
  cout<<ans;
}
