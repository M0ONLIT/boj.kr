#include<iostream>
#include<algorithm>
#include<vector>
#define endl '\n'
#define ioset() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define inf (1000000000)
using namespace std;

int n;
vector<int> v;

int relu(int x){
    return x>0?x:0;
}

class node{
public:
  int left, right, mid, evt;
  // evt는 누적합..
  node(){
    left=right=mid=evt=0;
  }
  node(int init){
    left=right=mid=evt=init;
  }
  node(int left, int right, int mid, int evt){
    this->left=left;
    this->right=right;
    this->mid=mid;
    this->evt=evt;
  }
  node operator+(node x){
    if(evt==-inf)
        return x;
    if(x.evt==-inf)
        return *this; //
    int l=max(left, evt+x.left);
    int r=max(x.right, x.evt+right);
    int m=max(max(mid, x.mid), right+x.left);
    int e=evt+x.evt;
    
    return node(l, r, m, e);
  }
};

//<입력정보 타입, 저장정보 타입>
class segment_tree{
public:
  vector<int> info;
  vector<node> v;
  int m;

  segment_tree(vector<int> &x){
    m=x.size();
    v=vector<node>(m*4+10);
    info=x;
    
    make_tree(0, m-1, 1);
  }
  
  node make_tree(int start, int end, int i){
    int mid=(start+end)/2;
    if(start==end){
      v[i]=node(info[mid]);
      return v[i];
    }
    return v[i]=make_tree(start, mid, i*2)+make_tree(mid+1, end, i*2+1);
  }
  
  node sum(int x, int y){ //구간 합을 구한다.
    return sum(x, y, 0, m-1, 1);
  }
  node sum(int x, int y, int start, int end, int i){
    int mid=(start+end)/2;
    if(y<start || end<x)
      return node(-inf);
    else if(x<=start && end<=y)
      return v[i];
    else
      return sum(x, y, start, mid, i*2)+sum(x, y, mid+1, end, i*2+1);
  }
};

int main(){
    ioset();
    int i, x, t, p, q;
    
    cin>>n;
    for(i=0; i<n; i++){
        cin>>x;
        v.push_back(x);
    }
    segment_tree tree(v);
    
    cin>>t;
    while(t--){
        cin>>p>>q;
        node r=tree.sum(p-1, q-1);
        cout<<r.mid<<endl;
    }
}
