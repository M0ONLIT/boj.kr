#include<vector>
using namespace std;

class segment_tree{
public:
  vector<int> v;
  int n,m;

  segment_tree(int n, int m){
    this->m=m;
    this->n=n;
    v=vector<int>(4*n);
  }

  int find(int x,int y){
    return find(x,y,0,this->m-1,1)
  }
  int find(int x,int y,int start,int end,int i){
    int mid=(start+end)/2;
    if(y<start || end<x)
      return 0;
    else if(x<=start && end<=y)
      return v[i];
    else
      return find(x,y,start,mid,i*2)+find(x,y,mid+1,end,i*2+1);
  }

  void insert(int index){
    return insert(index, 1, 0, m-1, 1);
  }
  void insert(int index,int value,int start,int end,int i){
    int mid=(start+end)/2;
    if(index<start || end<index)
      return;
    else if(start==end && mid==index){
      v[i]+=value;
      return;
    }
    else{
      insert(index,value,start,mid,i*2);
      insert(index,value,mid+1,end,i*2+1);
      v[i]=v[i*2]+v[i*2+1];
      return;
    }
  }

};
