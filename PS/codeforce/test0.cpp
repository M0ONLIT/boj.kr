#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<deque>
#include<map>
#include<set>

#define int long long
#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
const int mod=998244353;
const int mx=100005;

int w, k, n, ans;
int ncr[61][61], F[mx];
vector<int> arr;

int f(int x){
    if(x<0) return 0;
    return F[x];
}

void print_state(){
    for(int i=0; i<=k+1; i++) cout<<F[i]<<' ';
    cout<<'\n';
}

void initialize(){ //전처리
    for(int i=0; i<=60; i++)
        for(int j=0; j<=60; j++)
            if(i<j) ncr[i][j]=0;
            else if(i==j || j==0) ncr[i][j]=1;
            else ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];
    F[0]=1;
    for(int i=1; i<=k+1; i++){
        for(int j=0; j<=min(i-1, w); j++){
            F[i]+=ncr[w][j]*F[i-j-1]; F[i]%=mod;
        }
    }
    //print_state();
    for(int i=1; i<=k+1; i++){
        //F[i]+=F[i-1]; F[i]%=mod;
    }
}

void g(int idx, int k){
    if(k==0){
        ans++; ans%=mod;
    }
    if(k<0 || idx==n){
        return;
    }
    int bitcount=0;
    for(int bit=w-1; bit>=0; bit--){
        if((arr[idx]>>bit)&1){
            for(int i=0; i<=bit; i++){
                ans+=ncr[bit][i]*f(k-i-bitcount-1); ans%=mod;
            }
            bitcount++;
        }
    }
    g(idx+1, k-bitcount-1);
}

signed main() {
    ioset();
    cin>>w>>k>>n;
    arr.resize(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    initialize();
    for(int i=0; i<=k+1; i++) {g(0, i); cout<<ans<<' '; }
    //g(0, k+1);
    cout<<ans;
}
