#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
    ioset();
    int n, ans=0;
    cin>>n;
    for(int i=0; i<=n; i++){
        for(int j=i; j!=0; j/=10){
            ans+=(j%10==3 || j%10==6 || j%10==9);
        }
    }
    cout<<ans;
}
