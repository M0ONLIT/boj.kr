#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<cmath>
#include<limits>
#include<cassert>

#define int long long
#define ioset() ios_base::sync_with_stdio(0), cin.tie(0)
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, double> iid;
const int inf=numeric_limits<int>::max();
const int mx=10005;
int n, x, y;
int dp[2][mx][mx];
vector<pii> v;
signed main() {
    ioset();
    cin>>n>>x>>y;
    v.resize(n);
    for(int i=0; i<n; i++) cin>>v[i].first>>v[i].second;
    for(int i=0; i<n; i++){
        for(int xx=0; xx<=x; xx++){
            for(int yy=0; yy<=y; yy++){
                int p=v[i].first, q=v[i].second;
                if(i==0){
                    dp[i][xx][yy]=1;
                    continue;
                }
                dp[i%2][xx][yy]=dp[(i+1)%2][xx][yy];
                if(xx-p<0 || yy-q<0) dp[i%2][xx][yy]=max(1LL, dp[i%2][xx][yy]);
                else dp[i%2][xx][yy]=max(1+dp[(i+1)%2][xx-p][yy-q], dp[i%2][xx][yy]);
            }
        }
    }
    cout<<dp[(n-1)%2][x][y];
}
