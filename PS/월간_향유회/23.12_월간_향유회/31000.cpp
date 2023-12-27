#include<iostream>
using namespace std;

int main(){
    int n, i, j, ans=0;
    cin>>n;
    for(i=-n; i<=n; i++) for(j=-n; j<=n; j++) if((1-n<=i+j && i+j<=1+n)){
        if(i==0) continue;
        ans++;
    }
    cout<<ans+(2*n+1)*(2*n+1);
}
