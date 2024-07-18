#include<bits/stdc++.h>
#define int long long
#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

template<typename U>
class segment_tree {
public:
  vector<U> info;
  vector<U> v;
  int m;

  segment_tree() {}
  segment_tree(int x){
    m = x;
    v = vector<U>(m * 4);
    info = vector<U>(m);
    make_tree(0, m - 1, 1);
  }
  segment_tree(vector<U>& x) {
    m = x.size();
    v = vector<U>(m * 4);
    info = x;
    make_tree(0, m - 1, 1);
  }

  U make_tree(int start, int end, int i) {
    int mid = (start + end) / 2;
    if (start == end)
      return v[i] = info[mid];
    return v[i] = make_tree(start, mid, i * 2) + make_tree(mid + 1, end, i * 2 + 1);
  }

  U sum(int x, int y) {
    U p(-1);
    vector<U> ans;
    sum(x, y, 0, m - 1, 1, ans);
    for(auto i: ans) p=p+i;
    return p;
  }
  void sum(int x, int y, int start, int end, int i, vector<U> &ans) {
    int mid = (start + end) / 2;
    if (y < start || end < x)
      return;
    else if (x <= start && end <= y)
      ans.push_back(v[i]);
    else{
        sum(x, y, start, mid, i * 2, ans);
        sum(x, y, mid + 1, end, i * 2 + 1, ans);
        return;
    }
  }
};

class node{
public:
    int l, r, cnt_total, cnt_r, sz;
    node(): l(-1) {}
    node(int x): l(x), r(x), cnt_total(0), cnt_r(0), sz(1) {}
    node(int x, int y, int w, int z, int s): l(x), r(y), cnt_total(w), cnt_r(z), sz(s) {}
    node operator+(const node& other) const {
        if(l==-1) return other;
        if(other.l==-1) return *this;
        int new_cnt_r=max((int)ceil(cnt_r+log2((double)r/other.l)), 0LL);
        return node(l, other.r, cnt_total+new_cnt_r*other.sz+other.cnt_total, other.cnt_r+new_cnt_r, sz+other.sz);
    }
};

signed main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    vector<node> v(n);
    for(int i=0; i<n; i++){
        int x; cin>>x;
        v[i]=node(x);
    }
    segment_tree<node> seg(v);
    while(q--){
        int x, y; cin>>x>>y;
        node ans=seg.sum(x-1, y-1);
        cout<<ans.cnt_total<<'\n';
    }
}
