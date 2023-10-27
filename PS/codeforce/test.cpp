#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<deque>
#include<queue>
#include<time.h>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mx=200005;

int n, c[mx], d[mx], visit[mx];
vector<int> tree[mx];
deque<pii> Q;

int solve(){
  int i, cnt, ans=n-1;
  vector<int> p;
  for(i=1; i<=n; i++){
    if(c[i]){
      cnt=0;
      for(int near: tree[i])
        cnt+=d[i]<d[near];
      if(!cnt)
        p.push_back(d[i]);
    }
  }
  for(int i: p)
    ans=min(i, ans);
  return ans;
}

bool chk(int);
int solve2(){
  int start=0, end=n-1, mid;
  while(start<end){
    mid=(start+end)/2+1;
    if(chk(mid))
      start=mid;
    else
      end=mid-1;
  }
  return mid;
}

bool chk(int a){
    bool wego[200001];
    vector<int> visit(n+1,2e9);
    queue<pair<int,int>> q2;
    for(int x=1;x<=n;x++) {
        wego[x]=false;
        if(c[x] && d[x]>=a){
            q2.push({x,0});
            visit[x]=0;
        }
        else{
            visit[x]=2e9;
        }
    }
    while(!q2.empty()){
        int now=q2.front().first;
        int dist=q2.front().second;
        q2.pop();
        if(dist==a) break;
        wego[now]=true;
        for(auto i : tree[now]){
            if(visit[i]>dist+1 && c[i]){
                visit[i]=dist+1;
                q2.push({i,dist+1});
            }
        }
    }
    for(int x=1;x<=n;x++){
        if(c[x] && !wego[x]) return false;
    }
    return true;
}

int randint(int a, int b){ //2~99
  return rand()%(b-a+1)+a;
}

void setting(int n){
  int i, a, b;
  for(i=1; i<=n; i++){
    c[i]=rand()%2;
    tree[i].clear();
    visit[i]=d[i]=0;
  }
  for(i=2; i<=n; i++){ // 트리 입력
    a=i;
    b=randint(1, i-1);
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
}

void print_status(){
  int i;
  cout<<"c: ";
  for(i=1; i<=n; i++) cout<<c[i]<<' ';
  cout<<'\n';

  cout<<"d: ";
  for(i=1; i<=n; i++) cout<<d[i]<<' ';
  cout<<'\n';

  cout<<"node: \n";
  for(i=1; i<=n; i++){
    cout<<i<<": ";
    for(int nxt: tree[i]){
      cout<<nxt<<", ";
    }
    cout<<'\n';
  }

}

int main(){
  ioset();
  srand(time(0));
  n=10;
  while(1){
    setting(n);

    int ans1=solve();
    int ans2=solve2();
    if(ans1!=ans2){
      cout<<"ERROR FOUND!\n";
      cout<<"ans1: "<<ans1<<", ans2: "<<ans2<<'\n';
      print_status();
      break;
    }
  }
}
