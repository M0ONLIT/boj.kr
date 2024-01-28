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
int n, m;
int dp[5005][5005];
string p, q;

int main(){
    ioset();
    int i, j;

    cin>>n>>m>>p>>q;
    for(j=m-1; j>=0; j--){
        for(i=0; i<n; i++){
            if(j==m-1){
                dp[i][j]=p[i]==q[j];
                continue;
            }
            if(i==0)
                dp[i][j]=(p[i]==q[j])+dp[i+1][j+1];
            else if(i==n-1)
                dp[i][j]=(p[i]==q[j])+dp[i-1][j+1];
            else
                dp[i][j]=(p[i]==q[j])+max(dp[i-1][j+1], dp[i+1][j+1]);
        }
    }
    int ans=dp[0][0];
    for(i=0; i<n; i++)
        ans=max(ans, dp[i][0]);
    cout<<ans;
}
