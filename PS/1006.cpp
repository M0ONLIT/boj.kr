#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
#define ioset() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define std using namespace std
std; //state 해쉬화를 어떻게 시켜야 하지..
typedef long long ll;
const int MAX=20005, u=0, l=1, r=2;
const ll inf=9876543210;

int tagon[MAX];
int able[MAX][3];
int dp[MAX/2][4][4];
int visit[MAX/2][4][4];
int n, t, w;

int up(int x){
    if(x>n) return x-n;
    return x+n;
}
int left(int x){
    if(x==1) return n;
    if(x==n+1) return 2*n;
    return x-1;
}
int right(int x){
    if(x==n) return 1;
    if(x==2*n) return n+1;
    return x+1;
}

ll f(int index, int last, int now){
    int now_u, now_d;
    ll ans;
    now_u=now&2;
    now_d=now&1;
    
    if(index==n){
        int p=(last | now);
        if(p==3)
            return 0;
        if(p==0){
            if(able[index][u])
                return 1;
            return 2;
        }
        return 1;
    }
    if(visit[index][last][now])
        return dp[index][last][now];
    
    if(now_u && now_d){
        ans=f(index+1, last, 0);
    }
    else if(now_u){
        ans=f(index+1, last, 0)+1;
        if(able[index][r])
            ans=min(ans, f(index+1, last, 1)+1);
    }
    else if(now_d){
        ans=f(index+1, last, 0)+1;
        if(able[up(index)][r])
            ans=min(ans, f(index+1, last, 2)+1);
    }
    else{
        ans=f(index+1, last, 0)+2; //그냥 무식하게 2개 채우기
        if(able[index][u])
            ans=min(ans, f(index+1, last, 0)+1);
        if(able[index][r] && able[up(index)][r])
            ans=min(ans, f(index+1, last, 3)+2);
        else if(able[index][r])
            ans=min(ans, f(index+1, last, 1)+2);
        else if(able[up(index)][r])
            ans=min(ans, f(index+1, last, 2)+2);
    }
    visit[index][last][now]=1;
    return dp[index][last][now]=ans;
}

int main(){
    ioset();
    int i;
    
    cin>>t;
    while(t--){
        ll ans;
        cin>>n>>w;
        for(i=1; i<=2*n; i++)
            cin>>tagon[i];
        for(i=1; i<=2*n; i++){
            if(tagon[left(i)]+tagon[i]<=w)
                able[i][l]=1;
            if(tagon[up(i)]+tagon[i]<=w)
                able[i][u]=1;
            if(tagon[right(i)]+tagon[i]<=w)
                able[i][r]=1;
        }
        
        ans=f(1, 0, 0);
        if(able[1][l] && able[up(1)][l])
            ans=min(ans, f(1, 3, 3)+2);
        if(able[1][l])
            ans=min(ans, f(1, 1, 1)+1);
        if(able[up(1)][l])
            ans=min(ans, f(1, 2, 2)+1);
        cout<<ans<<'\n';
        
        fill(tagon, tagon+MAX, 0);
        fill(*able, *able+MAX*3, 0);
        fill(**dp, **dp+MAX/2*4*4, 0);
        fill(**visit, **visit+MAX/2*4*4, 0);
    }
}
