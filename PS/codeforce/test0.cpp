#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;

class segment_tree {
public:
  vector<ll> info;
  vector<ll> v;
  ll m;

  segment_tree() {}
  segment_tree(ll x){
    m = x;
    v = vector<ll>(m * 4);
    info = vector<ll>(m);
    make_tree(0, m - 1, 1);
  }
  segment_tree(vector<ll>& x) {
    m = x.size();
    v = vector<ll>(m * 4);
    info = x;
    make_tree(0, m - 1, 1);
  }

  ll make_tree(ll start, ll end, ll i) {
    ll mid = (start + end) / 2;
    if (start == end)
      return v[i] = info[mid];
    return v[i] = make_tree(start, mid, i * 2) + make_tree(mid + 1, end, i * 2 + 1);
  }

  ll sum(ll x, ll y) { // 구간 합을 구한다.
    return sum(x, y, 0, m - 1, 1);
  }
  ll sum(ll x, ll y, ll start, ll end, ll i) {
    ll mid = (start + end) / 2;
    if (y < start || end < x)
      return 0;
    else if (x <= start && end <= y)
      return v[i];
    else
      return sum(x, y, start, mid, i * 2) + sum(x, y, mid + 1, end, i * 2 + 1);
  }

  void insert(ll index, ll value) {
    return insert(index, value, 0, m - 1, 1);
  }
  void insert(ll index, ll value, ll start, ll end, ll i) {
    ll mid = (start + end) / 2;
    if (index < start || end < index)
      return;
    else if (start == end && mid == index) {
      v[i] = value;
      return;
    }
    else {
      insert(index, value, start, mid, i * 2);
      insert(index, value, mid + 1, end, i * 2 + 1);
      v[i] = v[i * 2] + v[i * 2 + 1];
      return;
    }
  }

  void init(ll x) {
    fill(v.begin(), v.end(), x);
  }
};

int main(){
    ioset();
    ll n, m, k, i;

    cin>>n>>m>>k;
    vector<ll> v(n);
    for(i=0; i<n; i++)
        cin>>v[i];

    segment_tree tree(v);
    for(i=0; i<m+k; i++){
        ll a, b, c;
        cin>>a>>b>>c;
        if(a==1) tree.insert(b-1, c);
        else cout<<tree.sum(b-1, c-1)<<'\n';
    }
}
