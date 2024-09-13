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

class segment_tree{
public:
  vector<int> info;
  vector<int> v;
  int m;

  segment_tree(vector<int> &x){
    m=x.size();
    v=vector<int>(m*4+5);
    info=x;
    make_tree(0, m-1, 1);
  }
  int make_tree(int start, int end, int i){
    int mid=(start+end)/2;
    if(start==end)
      return v[i]=info[mid];
    return v[i]=make_tree(start, mid, i*2)+make_tree(mid+1, end, i*2+1);
  }

  int sum(int x, int y){ //구간 합을 구한다.
    return sum(x, y, 0, m-1, 1);
  }
  int sum(int x, int y, int start, int end, int i){
    int mid=(start+end)/2;
    if(y<start || end<x)
      return 0;
    else if(x<=start && end<=y)
      return v[i];
    else
      return sum(x, y, start, mid, i*2)+sum(x, y, mid+1, end, i*2+1);
  }

  int find(int x){ //x번째 값을 찾는다. (0부터 시작)
      return find(x, 0, m-1, 1);
  }
  int find(int x, int start, int end, int i){
      int mid=(start+end)/2;
      if(start==end)
          return mid;
      if(x<=v[i*2])
          return find(x, start, mid, i*2);
      else
          return find(x-v[i*2], mid+1, end, i*2+1);
  }

  void insert(int index, int value){ //한 곳의 값을 value만큼 증감시킨다.
    insert(index, value, 0, m-1, 1);
    return;
  }
  void insert(int index, int value, int start, int end, int i){
    int mid=(start+end)/2;
    if(index<start || end<index)
      return;
    else if(start==end && mid==index){
      v[i]+=value;
      return;
    }
    else{
      insert(index, value, start, mid, i*2);
      insert(index, value, mid+1, end, i*2+1);
      v[i]=v[i*2]+v[i*2+1];
      return;
    }
  }

  void init(int x){
      fill(v.begin(), v.end(), x);
  }
};
