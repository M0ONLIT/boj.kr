#include<iostream>
#include<algorithm>
#include<vector>
#define endl '\n'
#define ioset() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define std using namespace std
#define inf (1LL<<61)
std;
typedef long long ll;
typedef pair<ll, ll> pll;

int visit[200005][2];
int able[200005];
ll dp[200005];
ll dp0[200005];
pll dp1[200005];
vector<ll> list0;
vector<pll> list1;
vector<int> graph[200005]; //i 의 부하

pll max(pll x, pll y){
    return (x.first+x.second>y.first+y.second)?x:y;
}

pll sum_pll(pll x, pll y){
    if(x.second>=y.first)
        return x;
    if(y.second>=x.first)
        return y;
    return {max(x.first, y.first), min(x.first, y.first)};
}

int compare_pll(pll x, pll y){
    return x.first+x.second>y.first+y.second;
}

int big(ll x, ll y){
    return x>y;
}

ll one(int x){
    if(visit[x][0]++)
        return dp0[x];
        
    ll ans=dp[x];
    for(int i: graph[x])
        if(dp[i]>0)
            ans=max(ans, one(i));
   
    return dp0[x]=ans;
}

pll two(int x){
    if(visit[x][1]++)
        return dp1[x];
    int size=0;
    for(int i: graph[x])
        size+=(dp[i]>0);
   
    if(size==0)
        return dp1[x]={-inf, -inf};
    if(size==1)
        for(int i: graph[x])
            if(dp[i]>0)
                 return dp1[x]=two(i);
        
    vector<ll> v0;
    for(int i: graph[x])
        v0.push_back(one(i));
    sort(v0.begin(), v0.end(), big);
    pll ans={v0[0], v0[1]};
    
    for(int i: graph[x])
        if(dp[i]>0)
            ans=max(ans, two(i));
    return dp1[x]=ans;
    
}

int main(){
    ioset();
    
    int n, i, p, q;
    cin>>n;
    for(i=1; i<=n; i++){
        cin>>p>>q;
        dp[i]=p;
        able[i]=1;
        if(q!=-1)
            graph[q].push_back(i);
    }
    
    for(i=n; i>0; i--){
        for(int j: graph[i])
            if(dp[j]>0){
                dp[i]+=dp[j];
                able[j]=0;
            }
    }
    
    for(i=1; i<=n; i++){
        if(able[i]){
            list0.push_back(one(i));
            list1.push_back(two(i));
        }
    }
    sort(list0.begin(), list0.end(), big);
    pll ans(-inf, -inf);
    if(list0.size()>1)
        ans={list0[0], list0[1]};
    for(pll i: list1)
        ans=max(ans, i);
    cout<<ans.first+ans.second;
}
