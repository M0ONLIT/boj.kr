#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<pair<int, int>> arr;
vector<pair<int, int>> v;
// value, index

int n, ans;
int main(){
  ios_base::sync_with_stdio(NULL);
  cin.tie(0); cout.tie(0);

  int i, x;
  cin>>n;
  for(i=0; i<n; i++){
    cin>>x;
    arr.push_back({x, i});
    v.push_back({x, i});
  }
  sort(arr.begin(), arr.end());

  for(i=0; i<n; i++)
    v[arr[i].second].first=i;

  for(i=0; i<n; i++)
    cout<<v[i].first<<' ';
  cout<<endl;

  for(i=1; i<n; i++){
    if(v[i-1].first+1 != v[i].first)
      ans++;
  }
  cout<<min(ans+1, 3);
}
