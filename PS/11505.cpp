#include<vector>
#include<iostream>
using namespace std;
typedef long long ll;
const int nanugi=1000000007;

class segment_tree{
public:
  vector<ll> info;
  vector<ll> v;
  int m;

  segment_tree(vector<ll> &x){
    m=x.size();
    v=vector<ll>(m*2);
    info=x;
    make_tree(0, m-1, 1);
  }
  ll make_tree(int start, int end, int i){
    int mid=(start+end)/2;
    if(start==end)
      return v[i]=info[mid];
    return v[i]=make_tree(start, mid, i*2)*make_tree(mid+1, end, i*2+1)%nanugi;
  }

  ll find(int x, int y){
    return find(x, y, 0, this->m-1, 1);
  }
  ll find(int x, int y, int start, int end, int i){
    int mid=(start+end)/2;
    if(y<start || end<x)
      return 1;
    else if(x<=start && end<=y)
      return v[i];
    else
      return find(x, y, start, mid, i*2)*find(x, y, mid+1, end, i*2+1)%nanugi;
  }

  void insert(int index, int value){
    return insert(index,  value,  0,  m-1,  1);
  }
  void insert(int index, int value, int start, int end, int i){
    int mid=(start+end)/2;
    if(index<start || end<index)
      return;
    else if(start==end && mid==index){
      v[i]=value;
      return;
    }
    else{
      insert(index, value, start, mid, i*2);
      insert(index, value, mid+1, end, i*2+1);
      v[i]=v[i*2]*v[i*2+1]%nanugi;
      return;
    }
  }

  void print(){
  	int i;
  	for(i=0; i<m; i++)
  	  cout<<info[i]<<" ";
  }
};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll n, m, k, i;
	vector<ll> v;
	cin>>n>>m>>k;

	for(i=0; i<n; i++){
		int x;
		cin>>x;
		v.push_back(x);
	}

	segment_tree tree(v);

	for(i=0; i<m+k; i++){
		int p, q, r;
		cin>>p>>q>>r;

		if(p==1){
			tree.insert(q-1, r);
		}
		else{
			cout<<tree.find(q-1, r-1)<<'\n';
		}
	}
	//tree.print();
}
