#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

class lazy_segment_tree {
public:
  vector<int> info;
  vector<int> v;
  vector<pii> lazy; // Lazy 업데이트를 저장하는 배열
  int m;

  lazy_segment_tree() {}
  lazy_segment_tree(vector<int>& x) {
    m = x.size();
    v = vector<int>(m * 4);
    lazy = vector<pii>(m * 4);
    info = x;
  }

  int find(int x) {
    return find(x, 0, m - 1, 1);
  }

  int find(int x, int start, int end, int i) {
    if (lazy[i].first == 1) { //반전
      if (start != end) {
        if(lazy[i * 2].first==0) lazy[i * 2].first=1;
        else if(lazy[i * 2].first==1) lazy[i * 2].first=0;
        else if(lazy[i * 2].first==2) lazy[i * 2].second^=1;

        if(lazy[i * 2 + 1].first==0) lazy[i * 2 + 1].first=1;
        else if(lazy[i * 2 + 1].first==1) lazy[i * 2 + 1].first=0;
        else if(lazy[i * 2 + 1].first==2) lazy[i * 2 + 1].second^=1;
      }
      else{
        v[i]^=1;
      }
      lazy[i] = {0, 0};
    }
    if (lazy[i].first == 2) { //설정
      if (start != end) {
        lazy[i * 2]=lazy[i];
        lazy[i * 2 + 1]=lazy[i];
      }
      else{
        v[i]=lazy[i].second;
      }
      lazy[i] = {0, 0};
    }

    int mid = (start + end) / 2;
    if (x < start || x > end)
      return 0;
    else if (x == start && start==end)
      return v[i];
    else {
      int left = find(x, start, mid, i * 2);
      int right = find(x, mid + 1, end, i * 2 + 1);
      return left + right;
    }
  }

  void insert1(int x, int y) {
    insert1(x, y, 0, m - 1, 1);
  }

  void insert1(int x, int y, int start, int end, int i) {
    int mid = (start + end) / 2;
    if (y < start || x > end)
      return;
    else if (x <= start && end <= y) {
      if(lazy[i].first==0) lazy[i].first=1;
      else if(lazy[i].first==1) lazy[i].first=0;
      else if(lazy[i].first==2) lazy[i].second^=1;

      //cout<<lazy[i].first<<lazy[i].second;
    } else {
      if(lazy[i].first==2){
          lazy[i*2]=lazy[i];
          lazy[i*2+1]=lazy[i];
          lazy[i]={0, 0};
      }
      insert1(x, y, start, mid, i * 2);
      insert1(x, y, mid + 1, end, i * 2 + 1);
    }
  }

  void insert2(int x, int y, int value) {
    insert2(x, y, value, 0, m - 1, 1);
  }

  void insert2(int x, int y, int value, int start, int end, int i) {
    int mid = (start + end) / 2;
    if (y < start || x > end)
      return;
    else if (x <= start && end <= y) {
      lazy[i]={2, value};
    } else {
      if(lazy[i].first==1){
          if(lazy[i * 2].first==0) lazy[i * 2].first=1;
          else if(lazy[i * 2].first==1) lazy[i * 2].first=0;
          else if(lazy[i * 2].first==2) lazy[i * 2].second^=1;

          if(lazy[i * 2 + 1].first==0) lazy[i * 2 + 1].first=1;
          else if(lazy[i * 2 + 1].first==1) lazy[i * 2 + 1].first=0;
          else if(lazy[i * 2 + 1].first==2) lazy[i * 2 + 1].second^=1;

          lazy[i]={0, 0};
      }
      else if(lazy[i].first==2){
          lazy[i*2]=lazy[i];
          lazy[i*2+1]=lazy[i];
          lazy[i]={0, 0};
      }
      insert2(x, y, value, start, mid, i * 2);
      insert2(x, y, value, mid + 1, end, i * 2 + 1);
    }
  }

  void init(int x) {
    fill(v.begin(), v.end(), x);
  }
};

int n, q;
int main(){
    //ioset();
    int o, l, r, c, x;
    cin>>n>>q;
    vector<int> v(200005);
    lazy_segment_tree tree(v);

    while(q--){
        cin>>o;
        if(o==1){
            cin>>l>>r;
            tree.insert1(l, r);
        }
        else if(o==2){
            cin>>l>>r>>c;
            tree.insert2(l, r, c);
        }
        else{
            cin>>x;
            cout<<tree.find(x)<<'\n';
        }
    }
    for(int i=1; i<=n; i++){
        cout<<tree.find(i);
    }
}
