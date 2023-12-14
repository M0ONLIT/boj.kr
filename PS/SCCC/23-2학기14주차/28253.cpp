#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll mod=998244353;
ll dp[100005][101][2];
ll visit[100005][101][2];
ll dp_x[101][101];
ll visit_x[101][101];
string L, R, X;
vector<int> pi;

vector<int> make_pi(string& s){
    vector<int> pi(s.size());
    int idx=0;
    for(int i=1; i<s.size(); i++){
        while(idx>0 && s[idx]!=s[i])
            idx=pi[idx-1];
        idx+=s[idx]==s[i];
        pi[i]=idx;
    }
    return pi;
}

ll ww2(string &p, int idx, char c){
    if(idx==p.size())
        return idx;
    if(visit_x[idx][c]++)
        return dp_x[idx][c];

    int ans_idx=idx;
    while(ans_idx>0 && p[ans_idx]!=c)
        ans_idx=pi[ans_idx-1];
    ans_idx+=p[ans_idx]==c;
    return dp_x[idx][c]=ans_idx;
}

ll ww(string &t, string &p, int idx_t, int idx_p, int option){ //1: 클수도 0 작음
    if(idx_t==t.size())
        return idx_p==p.size();
    if(visit[idx_t][idx_p][option]++)
        return dp[idx_t][idx_p][option];

    ll ans=0;
    for(int i=0; i<10; i++){
        char c=i+'0';
        if(option==1 && c>t[idx_t])
            continue;
        ans+=ww(t, p, idx_t+1, ww2(p, idx_p, c), option==1 && c==t[idx_t]);
        ans%=mod;
    }
    return dp[idx_t][idx_p][option]=ans;
}

void init(){
    fill(**visit, **visit+100005*101*2, 0);
    fill(*visit_x, *visit_x+101*101, 0);
}

string& minus1(string &s){
    int n=s.size();
    for(int i=n-1; i>=0; i--){
        if(s[i]=='0')
            s[i]='9';
        else{
            s[i]--;
            break;
        }
    }
    if(s[0]=='0')
        s.erase(s.begin());
    return s;
}

int main(){
    ioset();
    int i, j;
    cin>>L>>R>>X;
    pi=make_pi(X);
    ll ans1=ww(R, X, 0, 0, 1);
    init();
    ll ans2=ww(minus1(L), X, 0, 0, 1);
    cout<<(ans1-ans2+mod)%mod;
}
