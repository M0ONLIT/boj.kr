#include <vector>
using namespace std;

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
    if (start == end)
      return v[i] = start; // 해당 범위의 시작 인덱스 반환
    int mid = (start + end) / 2;
    int left = make_tree(start, mid, i * 2);
    int right = make_tree(mid + 1, end, i * 2 + 1);
    if (info[left] >= info[right])
      return v[i] = left;
    else
      return v[i] = right;
  }

  int find(int x, int y) {
    return find(x, y, 0, m - 1, 1);
  }

  int find(int x, int y, int start, int end, int i) {
    if (y < start || x > end)
      return -1; // 범위를 벗어난 경우
    if (x <= start && end <= y)
      return v[i]; // 현재 노드가 찾는 범위에 완전히 포함된 경우
    int mid = (start + end) / 2;
    int left = find(x, y, start, mid, i * 2);
    int right = find(x, y, mid + 1, end, i * 2 + 1);
    if (left == -1)
      return right;
    else if (right == -1)
      return left;
    else
      return (info[left] >= info[right]) ? left : right;
  }

  int get(int x, int y) {
    int maxIndex = find(x, y);
    return info[maxIndex];
  }

  void insert(int index, int value) {
    insert(index, value, 0, m - 1, 1);
  }

  void insert(int index, int value, int start, int end, int i) {
    if (index < start || end < index)
      return;
    if (start == end && index == start) {
      info[index] = value;
      v[i] = index;
      return;
    }
    int mid = (start + end) / 2;
    insert(index, value, start, mid, i * 2);
    insert(index, value, mid + 1, end, i * 2 + 1);
    if (info[v[i * 2]] >= info[v[i * 2 + 1]])
      v[i] = v[i * 2];
    else
      v[i] = v[i * 2 + 1];
  }

  void init(int x) {
    fill(v.begin(), v.end(), x);
  }
};
