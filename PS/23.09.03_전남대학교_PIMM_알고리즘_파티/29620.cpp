#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

const int nanugi=1000000007;
int n, m, x, y;
int arr[10][10], dp[50][50][6600], visit[50][50][6600]; //칸, cnt, bit

int loc_to_hash(int r, int c){
  return (r-1)*m+c;
}

void NEXT(int &r, int &c){
  c++;
  if(c>m){
    c-=m;
    r+=1;
  }
}

int dfs(int r, int c, int cnt, int bit){ // 남은 개수
  int R=r, C=c, i, j;
  int loc=loc_to_hash(r, c);
  int BIT=bit;
  int solve[m]; //solve=0: 아무도 없음, 1: 혼자있는인싸, 2: 여러명인 인싸
  for(i=0; i<m; i++){
    solve[i]=BIT%3;
    BIT/=3;
  }

  if(cnt==0){
    for(i=0; i<m; i++)
      if(solve[i]==1)
        return 0;
    return 1;
  }
  else if(loc>n*m)
    return 0;

  if(visit[loc][cnt][bit]++)
    return dp[loc][cnt][bit];

  if(arr[r][c]){ //인싸가 못들어가는 자리
    if(solve[m-1]==1)
      return dp[loc][cnt][bit]=0;
    else{
      BIT=0;
      for(i=m-2; i>=0; i--){
        BIT+=solve[i];
        BIT*=3;
      }
      NEXT(r, c);
      dp[loc][cnt][bit]=dfs(r, c, cnt, BIT);
      //cout<<R<<' '<<C<<' '<<cnt<<' '<<bit<<' '<<dp[loc][cnt][bit]<<endl;
      return dp[loc][cnt][bit];
    }
  }
  else{ //인싸가 들어갈 수 있는 자리
    if(solve[m-1]==1){
      for(i=0; i<c-1; i++){
        if(i==0 && solve[0])
          solve[0]=2;
        else if(solve[i] && solve[i-1])
          solve[i]=solve[i-1]=2;
      }

      BIT=0;
      for(i=m-2; i>=0; i--){
        BIT+=solve[i];
        BIT*=3;
      }
      BIT+=2;
      NEXT(r, c);
      dp[loc][cnt][bit]=dfs(r, c, cnt-1, BIT);
      //cout<<R<<' '<<C<<' '<<cnt<<' '<<bit<<' '<<dp[loc][cnt][bit]<<endl;
      return dp[loc][cnt][bit]=dfs(r, c, cnt-1, BIT);
    }
    else{
      ll ans=0;
      BIT=0;
      for(i=m-2; i>=0; i--){
        BIT+=solve[i];
        BIT*=3;
      }
      NEXT(r, c);
      ans+=dfs(r, c, cnt, BIT);
      // 안 들어갈 때

      r=R, c=C;
      for(i=0; i<c-1; i++){
        if(i==0 && solve[0])
          solve[0]=2;
        else if(solve[i] && solve[i-1])
          solve[i]=solve[i-1]=2;
      }
      BIT=0;
      for(i=m-2; i>=0; i--){
        BIT+=solve[i];
        BIT*=3;
      }
      if((c!=1 && solve[0]) || solve[m-1]) BIT+=2;
      else BIT+=1;
      NEXT(r, c);
      ans+=dfs(r, c, cnt-1, BIT);

      ans%=nanugi;
      dp[loc][cnt][bit]=ans;
      //cout<<R<<' '<<C<<' '<<cnt<<' '<<bit<<' '<<dp[loc][cnt][bit]<<endl;
      return dp[loc][cnt][bit]=ans;
    }
  }
}

int main(){
  ioset();
  int i, j;
  char c;
  cin>>n>>m>>x>>y;

  for(i=1; i<=n; i++) for(j=1; j<=m; j++){
    cin>>c;
    if(c=='A'){
      arr[i][j]=1;
      arr[i-1][j]=1;
      arr[i+1][j]=1;
      arr[i][j-1]=1;
      arr[i][j+1]=1;
    }
  }
  cout<<dfs(1, 1, x, 0);
}
