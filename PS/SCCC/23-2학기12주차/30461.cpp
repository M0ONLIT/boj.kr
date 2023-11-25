#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

int n, m, q;
ll arr[2001][2001];
bool visit[2001][2001];

ll ww(int r, int c){
  if(r==0 || c==0) return 0;
  if(visit[r][c]) return arr[r][c];
  visit[r][c]=1;

  return arr[r][c]=arr[r][c]+ww(r-1, c-1);
}

int main(){
  ioset();
  int i, j, r, c;
  cin>>n>>m>>q;
  for(i=1; i<=n; i++)
    for(j=1; j<=m; j++){
      cin>>arr[i][j];
      arr[i][j]+=arr[i-1][j];
    }

  while(q--){
    cin>>r>>c;
    cout<<ww(r, c)<<'\n';
  }
}
