#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<deque>
#include<memory.h>
#include<cassert>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long

using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> iii;
const int mx=1000000;
int dp[101][mx+5];
int arr[10005];

signed main() {
    ioset();
    int n, q; cin>>n>>q;
    vector<pii> v(n);
    for(int i=0; i<n; i++) cin>>v[i].second>>v[i].first; //first:길이, sec:가격
    sort(v.begin(), v.end());

    for(int i=0; i<n; i++){
        int len, val; tie(len, val)=v[i];
        if(i==0){
            dp[i][val]=len;
            continue;
        }
        dp[i][val]=len;
        for(int j=0; j<=mx; j++){
            dp[i][j]=max(dp[i][j], dp[i-1][j]);
            if(j>val && dp[i-1][j-val]>0) dp[i][j]=max(dp[i][j], dp[i-1][j-val]+len);
        }
    }
    int ptr=0;
    for(int i=0; i<=10000; i++){
        while(ptr<n && i>=v[ptr].first) ptr++;
        arr[i]=ptr-1;
    }

    for(int tc=0; tc<q; tc++){
        int a, b; cin>>a>>b; //a가 가격, b가 길이
        int idx=b<=10000?arr[b]:(n-1);
        if(idx<0 || dp[idx][a]<b) cout<<"NO\n";
        else cout<<"YES\n";

    }
}
