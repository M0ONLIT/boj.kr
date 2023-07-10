#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
ll s1, s2;

int c(pii x, pii y){
  if(x.first+x.second==y.first+y.second)
    return x.first>y.first;
  return x.first+x.second>y.first+y.second;
}
int d(pii x, pii y){
  return x.second>y.second;..
}

void print_vector(vector<pii> v){
  for(auto &i: v){
    cout<<i.first<<' '<<i.second<<'\n';
  }
  cout<<'\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int i, x, y;

  cin>>n>>m;
  vector<pii> v(n);
  for(i=0; i<n; i++) cin>>v[i].first;
  for(i=0; i<n; i++) cin>>v[i].second;

  sort(v.begin(), v.end(), c);
  for(i=0; i<m; i++) s1+=v[i].first;

  sort(v.begin()+m, v.end(), d);
  for(i=m; i<2*m; i++) s2+=v[i].second;

  cout<<s1-s2;
}
