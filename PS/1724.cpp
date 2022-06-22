// Online C++ compiler to run C++ program online
#include<iostream>
#include<algorithm>
#define ioset() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const int inf=987654321;

int n, m, t;
int greed[1005][1005];
void m2(int& x){x*=2;}
int dfs(int i, int j){
    if(i<0 || i>2*n || j<0 || j>2*m)
        return 0;
    if(greed[i][j])
        return 0;
    greed[i][j]=1;
    return (i%2 && j%2)+dfs(i-1, j)+dfs(i+1, j)+dfs(i, j-1)+dfs(i, j+1);
}
int main() {
    ioset();
    int i, j, k;
    int sx, sy, ex, ey;
    
    cin>>n>>m>>t;
    while(t--){
        cin>>sx>>sy>>ex>>ey;
        m2(sx);m2(sy);m2(ex);m2(ey);
        if(sx==ex){
            if(sy>ey) swap(sy, ey);
            for(i=sy; i<=ey; i++)
                greed[sx][i]=1;
        }
        if(sy==ey){
            if(sx>ex) swap(sx, ex);
            for(i=sx; i<=ex; i++)
                greed[i][sy]=1;
        }
    }
    int mini=inf, maxi=0;
    for(i=0; i<=2*n; i++) for(j=0; j<=2*m; j++){
        if(greed[i][j]==0){
            k=dfs(i, j);
            mini=min(k, mini);
            maxi=max(k, maxi);
        }
    }
    
    
    cout<<maxi<<'\n'<<mini;
}
