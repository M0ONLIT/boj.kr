#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int n, m, check[80005];
ll s1, s2;
vector<pll> v;

class segment_tree{
public:
  vector<int> info;
  vector<int> v;
  int m;

  segment_tree(vector<int> &x){
    m=x.size()-1;
    v=vector<int>(m*4);
    info=x;
    make_tree(0, m-1, 1);
  }
  int make_tree(int start, int end, int i){
    int mid=(start+end)/2;
    if(start==end)
      v[i]=info[mid];
    return v[i]=make_tree(start, mid, i*2)+make_tree(mid+1, end, i*2+1);
  }

  int sum(int x, int y){ //구간 합을 구한다.
    return sum(x, y, 0, m-1, 1);
  }
  int sum(int x, int y, int start, int end, int i){
    int mid=(start+end)/2;
    if(y<start || end<x)
      return 0;
    else if(x<=start && end<=y)
      return v[i];
    else
      return sum(x, y, start, mid, i*2)+sum(x, y, mid+1, end, i*2+1);
  }

  int find(int x, int y){
    return find(x, y, 0, m-1, 1);
  }
  int find(int x, int y, int start, int end, int i){
    int mid=(start+end)/2;
    if(y<start || end<x)
      return 0;
    else if(x<=start && end<=y)
      return v[i];
    else
      return find(x, y, start, mid, i*2)+find(x, y, mid+1, end, i*2+1);
  }

  void insert(int index){
    return insert(index,  1,  0,  m-1,  1);
  }
  void insert(int index, int value, int start, int end, int i){
    int mid=(start+end)/2;
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

  void init(int x){
      fill(v.begin(), v.end(), x);
  }
};


int c(pll x, pll y){
  if(x.first+x.second==y.first+y.second)
    return x.first>y.first;
  return x.first+x.second>y.first+y.second;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int i;

  cin>>n>>m;
  v=vector<pll>(n);
  for(i=0; i<n; i++) cin>>v[i].first;
  for(i=0; i<n; i++) cin>>v[i].second;

  sort(v.begin(), v.end(), c);
}
