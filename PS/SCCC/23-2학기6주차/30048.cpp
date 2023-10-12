#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int nanugi=1000000007;

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll dp[505][505], visit[505][505];
ll dp2[505][505], visit2[505][505];

ll ww(int, int);

ll www(int n, int e){
  if(n<=e) return 0;
  if(visit2[n][e]++) return dp2[n][e];

  return dp2[n][e]=(ww(n, e)+www(n, e+1))%nanugi;
}

ll ww(int n, int e){
  if(e<0 || n<=e || n<1) return 0;
  if(n==1) return e==0;
  if(visit[n][e]++) return dp[n][e];

  ll ans=0;
  int i, j;
  for(i=1; i<n-1; i++){
    ll p=ww(i, e), cnt=0;
    cnt=2*www(n-1-i, e+1);
    cnt%=nanugi;

    ans+=p*cnt;
    ans%=nanugi;
  }
  for(i=1; i<n-1; i++){
    ll p=ww(i, e), cnt=0;
    cnt+=ww(n-1-i, e);
    ans+=p*cnt;
    ans%=nanugi;
  }
  ans+=ww(n-1, e-1);
  ans%=nanugi;
  return dp[n][e]=ans;
}

int main(){
  ioset();
  int n, e;
  cin>>n>>e;
  cout<<ww(n, e);
}
