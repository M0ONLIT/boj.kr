#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll inf=109876543210;
ll n;
ll ans=-inf;
vector<ll> v, a, b;
ll S, E;

ll f(ll x, ll y){
  S=x, E=y;
  for(ll i=1; i<v.size(); i++){
    if(v[i-1]>0)
      v[i]+=v[i-1];
    else{
      S=x+i, E=y-i;
    }
  }
  return v[v.size()-1];
}

int main(){
  ioset();

  ll i, j, t, s, e;
  cin>>n;
  a=vector<ll>(n);
  b=vector<ll>(n);
  for(i=0; i<n; i++) cin>>a[i];
  for(i=0; i<n; i++) cin>>b[i];

  for(i=0; i<n; i++){
    for(j=0; j<i-j; j++)
      v.push_back(a[j]*b[i-j]+a[i-j]*b[j]);
    if(j==i-j)
      v.push_back(a[j]*b[j]);
    t=f(0, i);
    if(ans<t){
      ans=t;
      s=S, e=E;
    }
    /*
    cout<<0<<" "<<i<<' '<<t<<endl;
    for(ll k: v) cout<<k<<' ';
    cout<<endl;
    */
    v.clear();
  }

  for(i=n-1; i>=0; i--){
    for(j=i; j<n-1-j+i; j++)
      v.push_back(a[j]*b[n-1-j+i]+a[n-1-j+i]*b[j]);
    if(j==n-1-j+i)
      v.push_back(a[j]*b[j]);
    t=f(i, n-1);
    if(ans<t){
      ans=t;
      s=S, e=E;
    }
    /*
    cout<<i<<" "<<n-1<<' '<<t<<endl;
    for(ll k: v) cout<<k<<' ';
    cout<<endl;
    */
    v.clear();
  }
  cout<<s<<' '<<n-1-e<<'\n';
  cout<<ans;
}
