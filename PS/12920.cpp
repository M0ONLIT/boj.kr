#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll n, m;
ll dp[10005], temp[10005];
vector<pll> info;
int main(){
    ioset();
    int i, j, k, w, val, cnt;

    cin>>n>>m;
    for(i=0; i<n; i++){
        ll temp=1;
        cin>>w>>val>>cnt;
        while(temp<=cnt){
            info.push_back({w*temp, val*temp}); //무게, 만족도
            cnt-=temp;
            temp*=2;
        }
        if(cnt!=0)
            info.push_back({w*cnt, val*cnt});
    }
    n=info.size();
    for(i=0; i<n; i++){
        for(j=0; j<=m; j++){
            ll w, val;
            tie(w, val)=info[i];
            if(w<=j)
                dp[j]=max((i==0?0:temp[j-w])+val, i==0?0:temp[j]);
			else
				dp[j]=(i==0?0:temp[j]);
        }
        for(j=0; j<=m; j++) temp[j]=dp[j];
    }
    cout<<dp[m];
}
