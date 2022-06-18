#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define FOR(i, n) for(int i=1; i<=n; i++)
#define For(i, n) for(int i=0; i<n; i++)
#define endl '\n'
#define ioset() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define std using namespace std
std;
typedef long long ll;

int tree[262200], n;
vector<int> v;

void dfs(int node, int i, int j){
    int h=(int)log2(node)+1;
    if(n<node)
        return;
    
    dfs(node*2, i, j);
    if(i<=h && h<=j)
        v.push_back(tree[node]);
    dfs(node*2+1, i, j);
}

ll dp(){
    ll ans=v[0], t=v[0];
    for(int i=1; i<v.size(); i++){
        if(t>0) t+=v[i];
        else t=v[i];
        ans=max(ans, t);
    }
    return ans;
}

int main(){
    ioset();
    
    cin>>n;
    FOR(i, n)
        cin>>tree[i];
    int LOG=(int)log2(n)+1;
    ll ans=tree[1];
    FOR(i, LOG){
        for(int j=i; j<=LOG; j++){ //i<=j
            dfs(1, i, j);
            ans=max(ans, dp());
            v.clear();
        }
    }
    cout<<ans;
}
