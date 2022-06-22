// Online C++ compiler to run C++ program online
#include<iostream>
#include<algorithm>
#define ioset() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int dia[755][755];
int dpl[755][755], dpr[755][755];

int main() {
    ioset();
    int r, c, i, j, k;
    char x;
    cin>>r>>c;
    for(i=1; i<=r; i++) for(j=1; j<=c; j++){
        cin>>x;
        dia[i][j]=x-'0';
        if(dia[i][j]){
            dpl[i][j]=dpl[i-1][j-1]+1;
            dpr[i][j]=dpr[i-1][j+1]+1;
        }
    }
    
    int ans=0;
    for(i=1; i<=r; i++) for(j=1; j<=c; j++){
        int mini=min(dpl[i][j], dpr[i][j]);
        for(k=mini; k>ans; k--){
            if((i-k+1>=0) & (j-k+1>=0) & (j+k-1<=750))
                if((dpr[i-k+1][j-k+1]>=k) && (dpl[i-k+1][j+k-1]>=k)){
                    ans=k;
                }
        }
    }
    cout<<ans;
}
