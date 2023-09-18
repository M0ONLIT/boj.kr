#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

const int nanugi=1000000007;
int n, m, x, y;
int arr[10][10], dp[50][50][2200], visit[50][50][2200]; //칸, cnt, bit

int loc_to_hash(int r, int c){
  return (n-1)*r+c;
}

void NEXT(int &r, int &c){
  c++;
  if(c>m){
    c-=m;
    r+=1;
  }
}

int dfs(int r, int c, int cnt, int bit){ // 남은 개수
  int loc=loc_to_hash(r, c);
  int BIT=bit;
  if(cnt==0) return 1;
  else if(loc>n*m) return 0;

  if(visit[loc][cnt][bit]++)
    return dp[loc][cnt][bit];

  char solve[m]; //solve=0, 1, 2
  int i, j;
  for(i=0; i<m; i++){
    solve[i]=BIT%3;
    BIT/=3;
  }

  if(arr[r][c]==1){ //인싸가 못들어가는 자리
    if(solve[m-1]==1)
      return dp[loc][cnt][bit]=0;
    else{
      BIT=0;
      for(i=m-2; i>=0; i--){
        BIT+=solve[i];
        BIT*=3;
      }
      NEXT(r, c);
      return dp[loc][cnt][bit]=dfs(r, c, cnt, bit);
    }
  }
  else{ //인싸가 들어갈 수 있는 자리
    if(solve[m-1]==1){
      bit=0;
      for(i=m-2; i>=0; i--){
        bit+=solve[i];
        bit*=3;
      }
      NEXT(r, c);
      return dp[loc][cnt][bit]=dfs(r, c, cnt, bit);
    }
    else{
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
      arr[i][j+1]=1;
      arr[i-1][j-1]=1;
    }
  }
  cout<<dfs(1, 1, x, 0);
}
