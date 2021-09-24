
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>

using namespace std;
typedef long long ll;
const ll INF=1LL<<40;
ll dis[105][105];
int n, m;
int main(){
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL); cout.tie(NULL);

  int i, j, k;
  ll a, b, c;
  cin>>n>>m; //도시: 1~n
  for(i=1; i<=n; i++) for(j=1; j<=n; j++)
    dis[i][j]=INF;

  for(i=0; i<m; i++){
    cin>>a>>b>>c;
    dis[a][b]=min(dis[a][b], c);
  }
  for(i=1; i<=n; i++)
    dis[i][i]=0;

  for(i=1; i<=n; i++)
    for(j=1; j<=n; j++)
      for(k=1; k<=n; k++)
        dis[j][k]=min(dis[j][k], dis[j][i]+dis[i][k]);

  for(i=1; i<=n; i++){
    for(j=1; j<=n; j++)
      cout<<((dis[i][j]==INF)?0:dis[i][j])<<' ';
    cout<<'\n';
  }
}
