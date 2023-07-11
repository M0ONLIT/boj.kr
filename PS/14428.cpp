#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cassert>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

class segment_tree{
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
    tie(a, b)=make_tuple(make_tree(start, mid, i*2), make_tree(mid+1, end, i*2+1));

    return v[i]=info[a]<=info[b]?a:b;
  }

  int big(int x, int y){
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
      tie(a, b)=make_tuple(big(x, y, start, mid, i*2), big(x, y, mid+1, end, i*2+1));
      if(a==-1 || b==-1) return max(a, b);
      return info[a]<=info[b]?a:b;
    }
  }

  void insert(int index, int value){
    return insert(index, value, 0, m-1, 1);
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
      tie(a, b)={v[i*2], v[i*2+1]};
      v[i]=info[a]<=info[b]?a:b;
    }
  }

  void init(int x){
      fill(v.begin(), v.end(), x);
  }
};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, m, i, c, x, y;
  cin>>n;

  vector<int> v(n);
  for(i=0; i<n; i++) cin>>v[i];
  segment_tree T(v);

  cin>>m;
  for(i=0; i<m; i++){
    cin>>c>>x>>y;
    if(c==1){
      T.insert(x-1, y);
    }
    else{
      cout<<T.big(x-1, y-1)+1<<'\n';
    }
  }

}
