#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;
typedef long long ll;

const int nanugi=5000000;

class segment_tree{
public:
  vector<int> info;
  vector<int> v;
  int m;

  segment_tree(vector<int> &x){
    m=x.size();
    v=vector<int>(m*4+10);
    info=x;
    make_tree(0, m-1, 1);
  }
  
  int make_tree(int start, int end, int i){
    int mid=(start+end)/2;
    if(start==end)
      return v[i]=info[mid];
    return v[i]=(make_tree(start, mid, i*2)+make_tree(mid+1, end, i*2+1))%nanugi;
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
      return (sum(x, y, start, mid, i*2)+sum(x, y, mid+1, end, i*2+1))%nanugi;
  }
  
  int find(int x){ //x번째 값을 찾는다.
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
      v[i]%=nanugi;
      return;
    }
    else{
      insert(index, value, start, mid, i*2);
      insert(index, value, mid+1, end, i*2+1);
      v[i]=v[i*2]+v[i*2+1];
      v[i]%=nanugi;
      return;
    }
  }
};

vector<int> a, idx, dp, new_dp;

int compare(int x, int y){
    if(a[x]==a[y])
        return x>y;
    return a[x]<a[y];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k, i, _;
    cin>>n>>k;
    vector<int> x(n);
    if(k==1){
        cout<<n;
        return 0;
    }
    for(i=0; i<n; i++){
        cin>>_;
        a.push_back(_);
        idx.push_back(i);
    }
    sort(idx.begin(), idx.end(), compare);
    
    dp=vector<int>(n, 1);
    for(_=0; _<k-1; _++){
        segment_tree tree(x);
        new_dp=vector<int>(n);
        for(int i: idx){
            new_dp[i]=(i==0?0:tree.sum(0,i-1));
            tree.insert(i, dp[i]);
        }
        dp.swap(new_dp);
    }
    
    ll ans=0;
    for(int i: dp){
        ans+=i;
        ans%=nanugi;
    }
    cout<<ans;
}
