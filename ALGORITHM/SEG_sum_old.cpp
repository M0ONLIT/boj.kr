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

  U sum(int x, int y) { // 구간 합을 구한다.
    return sum(x, y, 0, m - 1, 1);
  }
  U sum(int x, int y, int start, int end, int i) {
    int mid = (start + end) / 2;
    if (y < start || end < x)
      return U();
    else if (x <= start && end <= y)
      return v[i];
    else
      return sum(x, y, start, mid, i * 2) + sum(x, y, mid + 1, end, i * 2 + 1);
  }
};
