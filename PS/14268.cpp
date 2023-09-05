#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

class lazy_segment_tree {
public:
  vector<int> info;
  vector<int> v;
  vector<int> lazy; // Lazy 업데이트를 저장하는 배열
  int m;

  lazy_segment_tree() {}
  lazy_segment_tree(int x) {
    m = x;
    v = vector<int>(m * 4);
    lazy = vector<int>(m * 4);
    info = vector<int>(m);
  }
  lazy_segment_tree(vector<int>& x) {
    m = x.size();
    v = vector<int>(m * 4);
    lazy = vector<int>(m * 4);
    info = x;
    make_tree(0, m - 1, 1);
  }

  int make_tree(int start, int end, int i) {
    if (start == end)
      return v[i] = info[start];
    int mid = (start + end) / 2;
    int left = make_tree(start, mid, i * 2);
    int right = make_tree(mid + 1, end, i * 2 + 1);
    return v[i] = left + right;
  }

  int sum(int x){
    return sum(x, 0, m-1, 1);
  }
  int sum(int x, int start, int end, int i) {
    if (lazy[i] != 0) {
      //v[i] += lazy[i]; //(end - start + 1)을 곱하지 않음
      if (start != end) {
        lazy[i * 2] += lazy[i];
        lazy[i * 2 + 1] += lazy[i];
      }
      else{ //수정
        v[i] += lazy[i];
      }
      lazy[i] = 0;
    }

    int mid = (start + end) / 2;
    if (x < start || x > end)
      return 0;
    else if (start==end && start==x)
      return v[i];
    else {
      int left = sum(x, start, mid, i * 2);
      int right = sum(x, mid + 1, end, i * 2 + 1);
      return left | right;
    }
  }

  void insert(int x, int y, int value) {
    insert(x, y, value, 0, m - 1, 1);
  }

  void insert(int x, int y, int value, int start, int end, int i) {

    int mid = (start + end) / 2;
    if (y < start || x > end)
      return;
    else if (x <= start && end <= y) {
      lazy[i] += value;
    } else {
      insert(x, y, value, start, mid, i * 2);
      insert(x, y, value, mid + 1, end, i * 2 + 1);
    }
  }

  void init(int x) {
    fill(v.begin(), v.end(), x);
  }
};

int n, m, ptr;
int s[100005], e[100005];
vector<int> tree[100005];

void dfs(int node){
  s[node]=++ptr;
  for(int i: tree[node])
    dfs(i);
  e[node]=ptr;
}

int main(){
  ioset();

  int i, k, o, p, q;
  cin >> n >> m;

  cin >> k;
  for(i = 2; i <= n; i++){
    cin >> k;
    tree[k].push_back(i);
  }
  dfs(1);
  lazy_segment_tree LST(ptr+1);

  for(i=1; i<=n; i++){
    cout<<s[i]<<' '<<e[i]<<endl;
  }

  for(i = 0; i < m; i++){
    cin >> o;
    if(o == 1){
      cin >> p >> q;
      LST.insert(s[p], e[p], q);
    }
    else{
      cin >> p;
      cout << LST.sum(s[p]) << '\n';
    }
  }
}
