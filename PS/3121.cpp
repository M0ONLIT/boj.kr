#include<iostream>
#include<algorithm>
#include<tuple>
#include<vector>

using namespace std;
typedef long long ll;

class point{
public:
  ll x, y;
  int color;
  point(){
      x=y=color=0;
  }
  point(ll x, ll y, char c){
    this->x=x;
    this->y=y;
    color=(c=='R'); //레드면 1 블루면 0
  }
};

int compare_point(const point &p1, const point &p2){
  if(p1.x==p2.x)
    return p1.y<p2.y;
  return p1.x<p2.x;
}

int compare_acc(const tuple<int, int, int, int> &p1, const tuple<int, int, int, int> &p2){
    ll x1, x2, y1, y2;
    y1=get<0>(p1); x1=get<1>(p1);
    y2=get<0>(p2); x2=get<1>(p2);
    if(y1*x2==y2*x1)
      return get<2>(p1)<get<2>(p2);
    return y1*x2<y2*x1;
}

int compare_acc_equal(const tuple<int, int, int, int> &p1, const tuple<int, int, int, int> &p2){
    ll x1, x2, y1, y2;
    y1=get<0>(p1); x1=get<1>(p1);
    y2=get<0>(p2); x2=get<1>(p2);
    if(y1*x2==y2*x1)
      return 1;
    return 0;
}

class node{
public:
  int left, right, mid, full;
  node(){
    left=right=mid=full=0;
  }
  node(int init){
    left=right=mid=full=init;
  }
  node(int left, int right, int mid, int full){
    this->left=left;
    this->right=right;
    this->mid=mid;
    this->full=full;
  }
  node operator+(node x){
    int l=left+(full?x.left:0);
    int r=x.right+(x.full?right:0);
    int m=max(max(mid, x.mid), right+x.left);
    int f=full&x.full;
    
    return node(l, r, m, f);
  }
};

//<입력정보 타입, 저장정보 타입>
class segment_tree{
public:
  vector<point> info;
  vector<node> v;
  int m;

  segment_tree(vector<point> x){
    m=x.size();
    v=vector<node>(m*4+10);
    info=x;
    
    make_tree(0, m-1, 1);
  }
  node make_tree(int start, int end, int i){
    int mid=(start+end)/2;
    if(start==end){
      v[i]=node(info[mid].color);
      return v[i];
    }
    return v[i]=make_tree(start, mid, i*2)+make_tree(mid+1, end, i*2+1);
  }

  int find(){
    return v[1].mid;
  }

  void insert(int index, int value){
    insert(index, value, 0, m-1, 1);
    return;
  }
  void insert(int index, int value, int start, int end, int i){
    int mid=(start+end)/2;
    if(index<start || end<index)
      return;
    else if(start==end && mid==index){
      v[i]=node(value);
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
vector<point> v;
vector<int> idx;
vector<tuple<int, int, int, int>> acc;

int main(){
  ll n;
  cin>>n;
  for(int i=0; i<n; i++){
    int x, y;
    char c;
    cin>>x>>y>>c;
    point p(x, y, c);
    v.push_back(p);
    idx.push_back(i);
  }
  sort(v.begin(), v.end(), compare_point);
  
  for(int i=0; i<n; i++) for(int j=i+1; j<n; j++){
    acc.push_back({v[i].y-v[j].y, v[i].x-v[j].x, i, j});
  }
  sort(acc.begin(), acc.end(), compare_acc);
  /*for(auto i: acc){
    ll _, __;
    int p, q;
    tie(_, __, p, q)=i;
    cout<<(double)_/__<<' '<<p<<' '<<q<<endl;
  }*/
  
  segment_tree tree(v);
  int ans=tree.find();
  for(int i=0; i<acc.size(); i++){
    ll _, __;
    int p, q, r;
    tie(_, __, p, q)=acc[i];
    swap(idx[p], idx[q]);
    swap(v[idx[p]], v[idx[q]]);
    tree.insert(idx[p], v[idx[p]].color);
    tree.insert(idx[q], v[idx[q]].color);
    if(i==acc.size()-1 || !compare_acc_equal(acc[i], acc[i+1]))
      ans=max(ans, tree.find());
    tree.insert(p, v[p].color);
    tree.insert(q, v[q].color);
    //cout<<p<<' '<<q<<' '<<ans<<endl;
  }
  cout<<ans;
  return 0;
}
