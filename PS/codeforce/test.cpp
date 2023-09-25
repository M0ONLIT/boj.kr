#include<iostream>
#include<vector>
#include<tuple>
#include<map>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int nanugi=1000000007;

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int n;
map<int, int> dic;
int main(){
  ioset();
  int i, j, k;
  cin>>n;
  vector<int> v(n);
  for(i=0; i<n; i++){
    cin>>v[i];
    dic[v[i]]++;
  }

  int ans=0;
  vector<int> ansv;

  for(i=1; i<n; i++){
    k=v[i]-v[0];
    for(j=1; j<n; j++){
      if(dic.find(v[j]-k)!=dic.end() || dic.find(v[j]+k)!=dic.end()){

      }
      else{
        break;
      }
    }
    if(j==n){
      ans++;
      ansv.push_back(k);
    }
  }

  cout<<ans<<'\n';
  for(int i: ansv) cout<<i<<' ';
}
