#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#define endl '\n'
#define ioset() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define inf (2121212121)
typedef long long ll;
using namespace std;
typedef tuple<ll, ll, ll> LLL;

int n;
ll ans;
vector<LLL> v;
vector<ll> info;

class node{
public:
  ll left, right, mid, evt;
  // evt는 누적합..
  node(){
    left=right=mid=evt=0;
  }
  node(ll init){
    left=right=mid=evt=init;
  }
  node(ll left, ll right, ll mid, ll evt){
    this->left=left;
    this->right=right;
    this->mid=mid;
    this->evt=evt;
  }
  node operator+(node x){
    ll l=max(left, evt+x.left);
    ll r=max(x.right, x.evt+right);
    ll m=max(max(mid, x.mid), right+x.left);
    ll e=evt+x.evt;
    
    return node(l, r, m, e);
  }
};

//<입력정보 타입, 저장정보 타입>
class segment_tree{
public:
  vector<ll> info;
  vector<node> v;
  int m;

  segment_tree(vector<ll> &x){
    m=x.size();
    v=vector<node>(m*4+10);
    info=x;
    
    //make_tree(0, m-1, 1);
  }
  
  node make_tree(int start, int end, int i){
    int mid=(start+end)/2;
    if(start==end){
      v[i]=node(info[mid]);
      return v[i];
    }
    return v[i]=make_tree(start, mid, i*2)+make_tree(mid+1, end, i*2+1);
  }
  
  ll sum(){
    return v[1].mid;
  }
  void insert(int index, node value){ //한 곳의 값을 value만큼 증감시킨다.
    insert(index, value, 0, m-1, 1);
    return;
  }
  void insert(int index, node value, int start, int end, int i){
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
      v[i]=v[i*2]+v[i*2+1];
      return;
    }
  }
  
  void clear(){
      fill(v.begin(), v.end(), node(0));
  }
};

int com_x(LLL p, LLL q){
    return get<0>(p)<get<0>(q);
}

int com_y(LLL p, LLL q){
    return get<1>(p)<get<1>(q);
}

int main(){
    ioset();
    ll i, j, x, y, w, ptr;
    
    cin>>n;
    for(i=0; i<n; i++){
        cin>>x>>y>>w;
        v.push_back({x, y, w});
    }
    info=vector<ll>(n);
    sort(v.begin(), v.end(), com_x);
    for(i=0, ptr=0; i<n; i++){
        if(i!=0 && get<0>(v[i-1])!=get<0>(v[i]))
            ptr++;
        info[i]=ptr;
    }
    for(i=0; i<n; i++)
        get<0>(v[i])=info[i];
    
    fill(info.begin(), info.end(), 0);
    segment_tree tree(info);
    sort(v.begin(), v.end(), com_y);
    for(i=0; i<n; i++){
        if(i==0 || get<1>(v[i])!=get<1>(v[i-1])){
            tree.clear();
            fill(info.begin(), info.end(), 0);
            for(j=i; j<n; j++){
                tie(x, y, w)=v[j];
                info[x]+=w;
                node N(info[x]);
                tree.insert(x, N);
                if(j==n-1 || get<1>(v[j])!=get<1>(v[j+1]))
                    ans=max(ans, tree.sum());
            }
        }
    }
    cout<<ans;
}
