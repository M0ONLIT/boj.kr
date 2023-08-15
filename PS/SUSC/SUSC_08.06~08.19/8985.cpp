#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<cassert>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll inf=10987654321;

class segment_tree{
public:
  vector<ll> info;
  vector<ll> v;
  ll m;

  segment_tree(){}
  segment_tree(vector<ll> &x){
    m=x.size();
    v=vector<ll>(m*4);
    info=x;
    make_tree(0, m-1, 1);
  }
  ll make_tree(ll start, ll end, ll i){
    ll mid=(start+end)/2;
    if(start==end)
      return v[i]=mid;
    ll p, q;
    p=make_tree(start, mid, i*2);
    q=make_tree(mid+1, end, i*2+1);
    return v[i]=info[p]<info[q]?p:q;
  }

  ll min(ll x, ll y){
    return min(x, y, 0, m-1, 1);
  }
  ll min(ll x, ll y, ll start, ll end, ll i){
    ll mid=(start+end)/2;
    if(y<start || end<x)
      return -1;
    else if(x<=start && end<=y)
      return v[i];
    else{
      ll p, q;
      p=min(x, y, start, mid, i*2);
      q=min(x, y, mid+1, end, i*2+1);
      if(p==-1) return q;
      if(q==-1) return p;
      return info[p]<info[q]?p:q;
    }
  }

  void insert(ll index){
    return insert(index, 1, 0, m-1, 1);
  }
  void insert(ll index, ll value, ll start, ll end, ll i){
    ll mid=(start+end)/2;
    if(index<start || end<index)
      return;
    else if(start==end && mid==index){
      v[i]+=value;
      return;
    }
    else{
      insert(index, value, start, mid, i*2);
      insert(index, value, mid+1, end, i*2+1);
      v[i]=v[i*2]+v[i*2+1];
      return;
    }
  }

  void init(ll x){
      fill(v.begin(), v.end(), x);
  }
};

class prefix_sum{
public:
  vector<ll> s;
  prefix_sum(){}
  prefix_sum(vector<ll> &v){
    s=vector<ll>(1);
    for(ll& i: v){
      s.push_back(i+s.back());
    }
  }
  ll sum(ll x, ll y){
    return s[y+1]-s[x];
  }
};

ll n, water;
double time;
vector<pii> p;
vector<ll> length, height, hole, s;
segment_tree HEIGHT;
prefix_sum HOLE, LENGTH;

double f(ll start, ll end, ll h){
  if(start>end) return -1;
  ll idx, cnt, l;
  cnt=HOLE.sum(start, end);
  l=LENGTH.sum(start, end);
  if(!cnt) return 0;
  else if(start==end){
    water-=(height[start]-h)*l;
    return (height[start]-h)*l;
  }
  idx=HEIGHT.min(start, end);
  water-=(height[idx]-h)*l;
  return max(
    f(start, idx-1, height[idx]),
    f(idx+1, end, height[idx])
  )+(double)(height[idx]-h)*l/cnt;
}

int main(){
  ioset();

  ll i, j, y1, x1, y2, x2, r, ptr;
  cin>>n;
  for(i=0; i<n; i++){
    pii x;
    cin>>x.first>>x.second;
    p.push_back(x);
  }
  for(i=1; i<n-1; i+=2){
    tie(x1, y1)=p[i];
    tie(x2, y2)=p[i+1];
    length.push_back(x2-x1);
    height.push_back(y1);
  }
  assert(length.size()==(n-2)/2);
  hole=vector<ll>(length.size());

  cin>>r;
  for(i=0; i<r; i++){
    cin>>x1>>y1>>x2>>y2;
    s.push_back(x1);
  }
  sort(s.begin(), s.end());
  j=0;
  for(i=ptr=0; i<length.size() && ptr<s.size(); i++){
    if(j==s[ptr]){
      hole[i]=1;
      ptr++;
    }
    j+=length[i];
  }
  for(i=0; i<length.size(); i++){
    water+=length[i]*height[i];
  }

  HEIGHT=segment_tree(height);
  HOLE=prefix_sum(hole);
  LENGTH=prefix_sum(length);

  /*
  for(auto i: s) printf("%d ", i);
  printf("\n");
  for(auto i: hole) printf("%d ", i);
  printf("\n");
  */
  time=f(0, length.size()-1, 0);
  printf("%.2lf\n%lld", time, water);
}
