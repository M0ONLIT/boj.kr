#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

class segment_tree {
public:
  vector<int> info;
  vector<int> v;
  int m;

  segment_tree() {}
  segment_tree(vector<int>& x) {
    m = x.size();
    v = vector<int>(m * 4);
    info = x;
    make_segment_tree(0, m - 1, 1);
  }

  int make_tree(int start, int end, int i) {
    int mid = (start + end) / 2;
    if (start == end)
      return v[i] = info[mid];
    return v[i] = make_tree(start, mid, i * 2) + make_tree(mid + 1, end, i * 2 + 1);
  }

  int sum(int x, int y) { // 구간 합을 구한다.
    return sum(x, y, 0, m - 1, 1);
  }
  int sum(int x, int y, int start, int end, int i) {
    int mid = (start + end) / 2;
    if (y < start || end < x)
      return 0;
    else if (x <= start && end <= y)
      return v[i];
    else
      return sum(x, y, start, mid, i * 2) + sum(x, y, mid + 1, end, i * 2 + 1);
  }

  void insert(int index) {
    return insert(index, 1, 0, m - 1, 1);
  }
  void insert(int index, int value, int start, int end, int i) {
    int mid = (start + end) / 2;
    if (index < start || end < index)
      return;
    else if (start == end && mid == index) {
      v[i] += value;
      return;
    }
    else {
      insert(index, value, start, mid, i * 2);
      insert(index, value, mid + 1, end, i * 2 + 1);
      v[i] = v[i * 2] + v[i * 2 + 1];
      return;
    }
  }

  void init(int x) {
    fill(v.begin(), v.end(), x);
  }
};

class Q {
  int option, a, b, c;
} query[100005];

int n, m, ptr;
int s[200005], e[200005], weight[100005];
vector<int> tree[200005];

void dfs(int node){
  s[node]=++ptr;
  for(int i: tree[node])
    dfs(i);
  e[node]=ptr;
}

int main(){
  ioset();

  int i, x, p, q, r, s;
  cin >> n >> m;
  for(i=1; i<=n; i++){
    cin>>x;
    if(i==1) continue;
    tree[x].push_back(i);
  }
  for(i=1; i<=n; i++)
    cin>>weight[i];

  for(i=0; i<m; i++){
    cin>>query[i].opion>>query[i].a;
    if(query[i].option==1)
      cin>>query[i].b>>query[i].c
      tree[query[i].a].push_back(query[i].b);
  }


}
