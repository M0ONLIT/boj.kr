#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int nanugi=1000000007;
const int MAX=2000000;
int n, m, k;
ll fac[MAX+5], fac_inv[MAX+5];
ll ans;
vector<pii> dots;

ll power(int n, int r){
  if(r==0) return 1;

  ll temp=power(n, r/2);
  temp=temp*temp%nanugi;

  if(r%2) temp=n*temp%nanugi;
  return temp;
}

void factorial_init(){
  int i;
  fac[0]=1;
  for(i=1; i<=MAX; i++){
    fac[i]=i*fac[i-1];
    fac[i]%=nanugi;
  }
  fac_inv[MAX]=power(fac[MAX], nanugi-2);
  for(i=MAX-1; i>=0; i--){
    fac_inv[i]=fac_inv[i+1]*(i+1)%nanugi;
  }
}

ll ncr(int n, int r){
  return fac[n]*fac_inv[n-r]%nanugi*fac_inv[r]%nanugi;
}

int check(int bit){
  int x(0), y(0);
  for(int i=0; i<k; i++){
    if((bit>>i)&1){
      if(x<=dots[i].first && y<=dots[i].second){
        x=dots[i].first;
        y=dots[i].second;
        continue;
      }
      return 1;
    }
  }
  return 0;
}

int main(){
  //ioset();
  int i, bit;
  factorial_init();
  cin>>n>>m>>k;
  for(i=0; i<k; i++){
    int x, y;
    cin>>x>>y;
    dots.push_back(make_pair(x, y));
  }
  sort(dots.begin(), dots.end());

  for(bit=0; bit<(1<<k); bit++){ //홀수개면 빼고 짝수개면 더하기
    if(check(bit))
      continue;

    int x(0), y(0), cnt(0), N, R;
    ll p=1;
    for(int i=0; i<k; i++){
      if((bit>>i)&1){
        cnt++;

        N=dots[i].first-x+dots[i].second-y;
        R=dots[i].second-y;
        p*=ncr(N, R);
        p%=nanugi;

        x=dots[i].first;
        y=dots[i].second;
      }
    }
    N=n-x+m-y;
    R=m-y;
    p*=ncr(N, R);
    p%=nanugi;
    if(cnt%2) ans+=nanugi-p;
    else ans+=p;
    ans%=nanugi;
  }
  cout<<ans;
}
