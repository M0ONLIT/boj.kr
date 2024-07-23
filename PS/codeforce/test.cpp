#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<deque>
#include<map>
#include<set>
#include<cmath>
#include<limits>

#define int long long
#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int inf=numeric_limits<int>::max();
const int mx=1000005;
const int mx2=200005;
const int mod=1000000007;

int ptr=0;
int trie[mx][30];
int trie_cnt[mx];
int visit[mx2], dp[mx2];

void add(string &s){
    int p=0;
    for(char c: s){
        int i=c-'a';
        if(trie[p][i]==0) trie[p][i]=++ptr;
        p=trie[p][i];
        trie_cnt[p]++;
    }
}

int f(int i, string &s){
    if(i==s.size()) return 1;
    if(visit[i]++) return dp[i];

    int p=0;
    int ans=0, cnt=0;
    do{
        if(i+cnt>s.size()) break;

        p=trie[p][s[i+cnt]-'a'];
        ans+=trie_cnt[p]*f(i+cnt+1, s);
        ans%=mod;
        cnt++;
    }while(p!=0);
    //cout<<i<<" "<<ans<<'\n';
    return dp[i]=ans;
}

signed main() {
    ioset();
    int n; cin>>n;
    for(int i=0; i<n; i++){
        string x; cin>>x;
        add(x);
    }
    string s; cin>>s;
    cout<<f(0, s);
}
