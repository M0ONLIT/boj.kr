#include <vector>
using namespace std;

class segment_tree {
public:
  vector<int> info;
  vector<vector<int>> v;
  int m;

  segment_tree() {}
  segment_tree(int x){
    m = x;
    v = vector<vector<int>>(m * 4);
    info = vector<int>(m);
    make_tree(0, m - 1, 1);
  }
  segment_tree(vector<int>& x) {
    m = x.size();
    v = vector<vector<int>>(m * 4);
    info = x;
    make_tree(0, m - 1, 1);
  }

  void make_tree(int start, int end, int i) {
    int mid = (start + end) / 2;
    if (start == end){
      v[i].push_back(info[mid]);
      return;
    }
    make_tree(start, mid, i * 2);
    make_tree(mid + 1, end, i * 2 + 1);

    int left_idx = 0, right_idx = 0;

    while (left_idx < v[i * 2].size() && right_idx < v[i * 2 + 1].size()) {
      if (v[i * 2][left_idx] < v[i * 2 + 1][right_idx]) {
        v[i].push_back(v[i * 2][left_idx]);
        left_idx++;
      } else {
        v[i].push_back(v[i * 2 + 1][right_idx]);
        right_idx++;
      }
    }

    while (left_idx < v[i * 2].size()) {
      v[i].push_back(v[i * 2][left_idx]);
      left_idx++;
    }

    while (right_idx < v[i * 2 + 1].size()) {
      v[i].push_back(v[i * 2 + 1][right_idx]);
      right_idx++;
    }
  }

  int sum(int value) {
    return sum(value, 0, m - 1, 1);
  }
  int sum(int value, int start, int end, int i) {
    int mid = (start + end) / 2;
    if (y < start || end < x)
      return 0;
    else if (x <= start && end <= y)
      return v[i].end() - upper_bound(v[i].begin(), v[i].end(), value);
    else
      return sum(x, y, start, mid, i * 2) + sum(x, y, mid + 1, end, i * 2 + 1);
  }
};
