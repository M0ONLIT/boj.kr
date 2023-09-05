#include<vector>
using namespace std;

class segment_tree{
public:
  vector<int> info;
  vector<int> v;
  int m;

  segment_tree(){}
  segment_tree(vector<int> &x){
    m=x.size();
    v=vector<int>(m*4);
    info=x;
    make_segment_tree(0, m-1, 1);
  }
  int make_tree(int start, int end, int i){
    int mid=(start+end)/2;
    if(start==end)
      return v[i]=info[mid];
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

  void insert(int index){
    return insert(index, 1, 0, m-1, 1);
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
