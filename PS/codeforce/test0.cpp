#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
ll n,x,y;
priority_queue<ll> q;
map<ll,int> mp;
vector<pair<ll, ll>> ans;

void go(ll num){
    if(num <= 2) return;
    for(ll i=0; i<=INF; i++){
        if(i*i < num) continue;
        x = i;
        y = i*i - num;
        break;
    }
    if(mp.find(x) == mp.end()){ mp[x] = 1; q.push(x); }
    if(mp.find(y) == mp.end()){ mp[y] = 1; q.push(y); }
    ans.push_back({x, y});
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    go(n);
    while(q.size()){
        go(q.top());
        q.pop();
    }
    while(ans.size()){
        auto t=ans.back(); ans.pop_back();
        cout<<t.first<<' '<<t.second<<'\n';
    }
}
