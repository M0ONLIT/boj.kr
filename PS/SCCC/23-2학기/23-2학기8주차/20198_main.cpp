#include<iostream>
#include<vector>
#include<set>
#include<tuple>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mx=200005;

int n, i, s[mx], ans=mx;

vector<int> tree[mx];
multiset<int> in, out;
multiset<int>::iterator it;

void update(int a, int b, int c){
  ans=min(max(max(a, b), c)-min(min(a, b), c), ans);
}

int count_subtree(int node, int mom){
  int ans=1;
  for(int nxt: tree[node]){
    if(nxt==mom)
      continue;
    ans+=count_subtree(nxt, node);
  }
  return s[node]=ans;
}

void solve(int node, int mom){
  it=in.lower_bound((n+s[node])/2);
  if(it!=in.end())
    update(s[node], *it-s[node], n-*it);
  if(it!=in.begin()){
    --it;
    update(s[node], *it-s[node], n-*it);
  }

  it=out.lower_bound((n-s[node])/2);
  if(it!=out.end())
    update(s[node], *it, n-s[node]-*it);
  if(it!=out.begin()){
    --it;
    update(s[node], *it, n-s[node]-*it);
  }

  in.insert(s[node]);
  for(int nxt: tree[node]){
    if(nxt==mom)
      continue;
    solve(nxt, node);
  }
  in.erase(s[node]);
  out.insert(s[node]);
}

int main(){
  ioset();

  cin>>n;
  for(i=0; i<n-1; i++){
    int x, y;
    cin>>x>>y;
    tree[x].push_back(y);
    tree[y].push_back(x);
  }
  count_subtree(1, 0);
  solve(1, 0);
  cout<<ans;
}
