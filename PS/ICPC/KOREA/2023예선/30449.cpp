#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef pair<int, int> pii;
bool check[5001][5001];

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.first * p2.second < p2.first * p1.second;
}

int main() {
  ioset();
  int n, k;
  cin >> n >> k;

  vector<pii> pairs={{0, 1}, {1, 1}};

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if(!check[j][i]) {
        check[j][i] = 1;
        pairs.push_back({j, i});
        for (int o = 2; o * i <= n; o++) {
          check[j * o][i * o]=1;
        }
      }
    }
  }

  nth_element(pairs.begin(), pairs.begin() + k - 1, pairs.end(), compare);

  cout << pairs[k - 1].first << " " << pairs[k - 1].second;
}
