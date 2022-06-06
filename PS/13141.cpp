#include<iostream>
#include<algorithm>
#include<vector>
#define for(i, n) for(int i=1; i<=n; i++)
#define endl '\n'
#define ioset() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define std using namespace std

std;
typedef long long ll;
ll inf=9876543210;

ll dp[205][205];
int n, m;
double ans=inf, ansp, t;
class node{
public:
    int s, e, l;
    node(){
        node(0, 0, 0);
    }
    node(int x, int y, int z){
        s=x; e=y; l=z;
    }
};
vector<node> v;

int main(){
    ioset();
    for(i, 204) for(j, 204)
        dp[i][j]=(i==j?0:inf);
        
    cin>>n>>m;
    ll s, e, l;
    v.push_back(node());
    for(i, m){
        cin>>s>>e>>l;
        dp[s][e]=dp[e][s]=min(l, dp[s][e]);
        v.push_back(node(s, e, l));
    }
    for(k, n) for(i, n) for(j, n){
        dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);
    }
    for(i, n){
        ansp=0;
        for(j, m){
            s=v[j].s; e=v[j].e; l=v[j].l;
            ansp=max(ansp, (double)(dp[i][s]+dp[i][e]+l)/2);
        }
        ans=min(ans, ansp);
    }
    printf("%.1lf", ans);
}
