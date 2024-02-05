#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

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


prefix_sum<int> S;

int main(){
  vector<int> v={1, 2, 3};
  S=prefix_sum<int>(v);
}
