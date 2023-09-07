#include<iostream>
#include<vector>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;

template <typename T>
class prefix_sum {
public:
  vector<T> s;

  prefix_sum() {}
  prefix_sum(vector<T> &v) {
    s = vector<T>(1);
    for (T &i : v) {
      s.push_back(i + s.back());
    }
  }
  T sum(int x, int y) {
    return s[y + 1] - s[x];
  }
};

int n;
ll ans[505];
int main(){
  ioset();

  int i, j, k;
  cin>>n;
  vector<ll> v(n);
  for(i=0; i<n; i++){
    cin>>v[i];
    ans[i]=v[i];
  }
  prefix_sum<ll> S(v);

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      
    }
  }
}
