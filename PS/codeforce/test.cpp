#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int nanugi=1000000007;

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template <typename T>
class prefix_sum {
public:
  vector<T> s;

  prefix_sum() {}
  prefix_sum(vector<T> &v) {
    s = vector<T>(1);
    for (T &i : v) {
      s.push_back((i + s.back())%nanugi);
    }
  }
  T sum(int x, int y) {
    if(x > y)
      return 0;
    return (s[y + 1] - s[x] + nanugi)%nanugi;
  }
};


int n;
vector<ll> v, v2, v3;

int main(){
  ioset();
  int i, j;
  cin>>n;
  v=vector<ll>(n);
  v2=vector<ll>(n);
  v3=vector<ll>(n);
  for(i=0; i<n; i++) cin>>v[i];
  prefix_sum<ll> S(v);
  for(i=0; i<n; i++) v2[i]=S.sum(i+1, n-1)*v[i]%nanugi;
  //for(int i: v2) cout<<i<<' ';
  prefix_sum<ll> S2(v2);
  for(i=0; i<n; i++) v3[i]=S2.sum(i+1, n-1)*v[i]%nanugi;
  //for(int i: v3) cout<<i<<' ';
  prefix_sum<ll> S3(v3);
  cout<<S3.sum(0, n-1);
}
