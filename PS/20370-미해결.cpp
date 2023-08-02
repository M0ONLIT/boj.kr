//https://www.acmicpc.net/problem/20370

#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cassert>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int n, k, check[80005];
ll ans;
vector<pll> v;
vector<int> p, q;

class segment_tree{ //세그먼트 트리 클래스
public:
  vector<int> info;
  vector<int> v;
  int m;

  segment_tree(vector<int> &x){
    m=x.size();
    v=vector<int>(m*4);
    info=x;
    make_tree(0, m-1, 1);
  }
  int make_tree(int start, int end, int i){
    int mid=(start+end)/2;
    if(start==end)
      return v[i]=mid;
    int a, b;
    a=make_tree(start, mid, i*2);
    b=make_tree(mid+1, end, i*2+1);
    return v[i]=info[a]>info[b]?a:b;
  }

  int big(int x, int y){ //구간 x~y에서 값이 가장 큰 index를 반환함(범위 0~n-1)
    return big(x, y, 0, m-1, 1);
  }
  int big(int x, int y, int start, int end, int i){
    int mid=(start+end)/2;
    if(y<start || end<x)
      return -1;
    else if(x<=start && end<=y)
      return v[i];
    else{
      int a, b;
      a=big(x, y, start, mid, i*2);
      b=big(x, y, mid+1, end, i*2+1);
      if(a==-1 || b==-1) return max(a, b);
      return info[a]>info[b]?a:b;
    }
  }

  void insert(int index){ //index번째에 있는 값을 0으로 바꿈
    return insert(index, 0, 0, m-1, 1);
  }
  void insert(int index, int value, int start, int end, int i){
    int mid=(start+end)/2;
    if(index<start || end<index)
      return;
    else if(start==end && mid==index){
      info[index]=value;
      return;
    }
    else{
      insert(index, value, start, mid, i*2);
      insert(index, value, mid+1, end, i*2+1);
      int a, b;
      a=v[i*2];
      b=v[i*2+1];
      v[i]=info[a]>info[b]?a:b;
    }
  }

  void init(int x){
      fill(v.begin(), v.end(), x);
  }
};

int comp(pll x, pll y){
  return x.second>y.second;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int i, x, y;

  cin>>n>>k;
  v=vector<pll>(n);
  p=vector<int>(n);
  q=vector<int>(n);
  for(i=0; i<n; i++) cin>>v[i].first;
  for(i=0; i<n; i++) cin>>v[i].second;
  sort(v.begin(), v.end(), comp);
  for(i=0; i<n; i++){
    p[i]=v[i].first+v[i].second;
    q[i]=v[i].first;
  }
  int ptr=k;
  segment_tree P(p), Q(q);

  for(i=0; i<k; i++){
    x=P.big(0, ptr-1);
    y=Q.big(ptr, n-1);

    if(p[x]-v[ptr].second>q[y]){
      check[x]++;
      P.insert(x);
      Q.insert(x);
      ptr++;
    }
    else{
      check[y]++;
      P.insert(y);
      Q.insert(y);
    }
    while(check[ptr]) ptr++;
  }

  x=0;
  for(i=0; i<n; i++){
    if(check[i]){
      ans+=v[i].first;
    }
    else if(x<k){
      ans-=v[i].second;
      x++;
    }
  }
  cout<<ans;
}
