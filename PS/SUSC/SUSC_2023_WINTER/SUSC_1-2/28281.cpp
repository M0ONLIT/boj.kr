#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf=(1LL<<63)-1;

ll a[100005];
int main(){
    ioset();

    int n, x, i;
    ll ans=inf;
    cin>>n>>x;
    for(i=0; i<n; i++){
        cin>>a[i];
        if(i!=0){
            ans=min(ans, a[i]+a[i-1]);
        }
    }
    cout<<ans*x;
}
