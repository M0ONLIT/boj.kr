#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m, k, w, arr[305][305], ans[305][305];

class segment_tree {
public:
  vector<int> info;
  vector<int> v;
  int m;

  segment_tree() {}
  segment_tree(int x){
    m = x;
    v = vector<int>(m * 4);
    info = vector<int>(m);
  }
  segment_tree(vector<int>& x) {
    m = x.size();
    v = vector<int>(m * 4);
    info = x;
    make_tree(0, m - 1, 1);
  }
  segment_tree(const segment_tree &x){
    m = x.m;
    v = x.v;
    info = x.info;
  }

  int make_tree(int start, int end, int i) {
    int mid = (start + end) / 2;
    if (start == end)
      return v[i] = info[mid];
    return v[i] = make_tree(start, mid, i * 2) + make_tree(mid + 1, end, i * 2 + 1);
  }

  int sum(int x, int y) { // 구간 합을 구한다.
    return sum(x, y, 0, m - 1, 1);
  }
  int sum(int x, int y, int start, int end, int i) {
    int mid = (start + end) / 2;
    if (y < start || end < x)
      return 0;
    else if (x <= start && end <= y)
      return v[i];
    else
      return sum(x, y, start, mid, i * 2) + sum(x, y, mid + 1, end, i * 2 + 1);
  }

  void insert(int index, int value) {
    return insert(index, value, 0, m - 1, 1);
  }
  void insert(int index, int value, int start, int end, int i) {
    int mid = (start + end) / 2;
    if (index < start || end < index)
      return;
    else if (start == end && mid == index) {
      v[i] += value;
      return;
    }
    else {
      insert(index, value, start, mid, i * 2);
      insert(index, value, mid + 1, end, i * 2 + 1);
      v[i] = v[i * 2] + v[i * 2 + 1];
      return;
    }
  }

  void paste(const segment_tree &x){
    m = x.m;
    info = x.info;
    v = x.v;
  }

  int find_ans(int cnt) {
    return find_ans(cnt, 0, m - 1, 1);
  }
  int find_ans(int cnt, int start, int end, int i){
    int mid = (start + end) / 2;
    if (start == end)
      return start;
    if(cnt > v[i * 2])
      return find_ans(cnt-v[i*2], mid+1, end, i*2+1);
    else
      return find_ans(cnt, start, mid, i*2);
  }


  void init(int x) {
    fill(v.begin(), v.end(), x);
  }
};

int main(){
  ioset();
  int i, j, p, q, r, c;
  cin>>n>>m>>k>>w;
  for(i=0; i<n; i++) for(j=0; j<m; j++) cin>>arr[i][j];

  segment_tree T(k+5);
  r=c=0;
  for(i=0; i<n-w+1; i++){
    for(j=0; j<m-w+1; j++){
      if(j==0){
        if(i==0){
          for(p=0; p<w; p++) for(q=0; q<w; q++)
            T.insert(arr[i+p][q], 1);
        }
        else{
          for(p=0; p<w; p++){
            T.insert(arr[i-1][c+p], -1); //밑으로 1칸 땡기기
            T.insert(arr[i+w-1][c+p], 1);
          }
          r++;
        }
      }
      else{
        if(!(i%2)){
          c++;
          for(p=0; p<w; p++){
            T.insert(arr[i+p][c-1], -1); //오른쪽으로 1칸 땡기기
            T.insert(arr[i+p][c+w-1], 1);
          }
        }
        else{
          c--;
          for(p=0; p<w; p++){
            T.insert(arr[i+p][c+w], -1);
            T.insert(arr[i+p][c], 1); //왼쪽으로 1칸 땡기기
          }
        }
      }
      //cout<<r<<' '<<c<<endl;
      ans[r][c]=T.find_ans(w*w/2+1);
    }
  }
  for(i=0; i<n-w+1; i++){
    for(j=0; j<m-w+1; j++)
      cout<<ans[i][j]<<' ';
    cout<<'\n';
  }
}
