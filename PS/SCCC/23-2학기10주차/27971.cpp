#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mx=100005;
int n, m, a, b, check[mx], dp[mx];

int main(){
  ioset();
  cin>>n>>m>>a>>b;
  while(m--){
    int x, y;
    cin>>x>>y;
    for(int i=x; i<=y; i++)
      check[i]=1;
  }

  for(int i=0; i<=n; i++){
    int ans=mx;
    if(check[i]) continue;
    if(a<=i && (dp[i-a]!=0 || i==a))
      ans=min(dp[i-a]+1, ans);
    if(b<=i && (dp[i-b]!=0 || i==b))
      ans=min(dp[i-b]+1, ans);
    dp[i]=ans==mx?0:ans;
  }
  cout<<(dp[n]?dp[n]:-1);
}
