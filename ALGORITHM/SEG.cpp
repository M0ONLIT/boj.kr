#include<vector>
using namespace std;

const int nanugi=1000000007;

class segment_tree{
public:
  vector<int> info;
  vector<int> v;
  int m;

  segment_tree(vector<int> &x){
    m=x.size()-1;
    v=vector<int>(m*4);
    info=x;
    make_segment_tree(0, m-1, 1);
  }
  int make_tree(int start, int end, int i){
    int mid=(start+end)/2;
    if(start==end)
      v[i]=info[mid];
    return v[i]=make_tree(start, mid, i*2)+make_tree(mid+1, end, i*2+1);
  }

  int find(int x, int y){
    return find(x, y, 0, this->m-1, 1)
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
};
