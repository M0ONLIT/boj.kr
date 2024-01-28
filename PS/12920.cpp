#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
const ll inf=(1LL<<63)-1;

ll n, m, info[105][3];
ll dp[105][10005];

int main(){
    ioset();
    int i, j, k;

    cin>>n>>m;
    for(i=0; i<n; i++){
        cin>>info[i][0]>>info[i][1]>>info[i][2];
    } //무게, 만족도, 개수;

    for(i=0; i<n; i++){
        for(j=0; j<=m; j++){
            ll ans=0;
            for(k=0; k<=info[i][2]; k++){
                if(j<k*info[i][0])
                    break;
                ans=max(ans, (i==0?0:dp[i-1][j-k*info[i][0]])+k*info[i][1]);
            }
            dp[i][j]=ans;
        }
    }
    cout<<dp[n-1][m];
}
