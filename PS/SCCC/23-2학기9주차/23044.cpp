#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<deque>
#include<queue>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mx=200005;

int n, c[mx], d[mx], visit[mx];
vector<int> tree[mx];
deque<pii> Q;
int check(int value){
  int i;
  Q.clear();
  for(i=1; i<=n; i++){
    if(d[i]>=value){
      Q.push_back(make_pair(i, 0));
    }
    visit[i]=0;
  }
  while(!Q.empty()){
    int now, dist;
    tie(now, dist)=Q.front(); Q.pop_front();
    if(dist>=value) continue;
    else if(visit[now]++) continue;

    for(auto i: tree[now]){
      Q.push_back(make_pair(i, dist+1));
    }
  }
  for(i=1; i<=n; i++){
    if(c[i] && !visit[i])
      return 0;
  }
  return 1;
}

int solve(){
  int start=1, end=n, mid;
  while(start<end){
    mid=(start+end)/2+1;
    if(check(mid))
      start=mid;
    else
      end=mid-1;
  }
  return start;
}

int main(){
  ioset();
  int i, a, b;
  cin>>n;
  for(i=1; i<=n; i++) cin>>c[i];
  for(i=0; i<n-1; i++){ // 트리 입력
    cin>>a>>b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  for(i=1; i<=n; i++){ //bfs의 시작 정점들
    if(!c[i])
      Q.push_back(make_pair(i, 0));
  }

  while(!Q.empty()){ //bfs
    int node, dis;
    tie(node, dis)=Q.front();
    Q.pop_front();

    if(visit[node]++)
      continue;
    d[node]=dis;

    for(int nxt: tree[node])
      Q.push_back(make_pair(nxt, dis+1));
  }

  cout<<solve();
}
