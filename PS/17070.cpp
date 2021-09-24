#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>

using namespace std;
int n;
int arr[20][20];
int dp1[20][20], dp2[20][20], dp3[20][20];

int main(){
  int i, j;
  scanf("%d", &n);
  for(i=1; i<=n; i++)
    for(j=1; j<=n; j++)
      scanf("%d", &arr[i][j]);

  dp1[1][2]=1;
  for(i=1; i<=n; i++){
    for(j=1; j<=n; j++){
      if(arr[i][j])
        continue;
      if(i==1 && j<=2)
        continue;

      dp1[i][j]=dp1[i][j-1]+dp3[i][j-1];
      dp2[i][j]=dp2[i-1][j]+dp3[i-1][j];

      if(arr[i-1][j] || arr[i][j-1])
        continue;
      dp3[i][j]=dp1[i-1][j-1]+dp2[i-1][j-1]+dp3[i-1][j-1];
    }
  }

  printf("%d", dp1[n][n]+dp2[n][n]+dp3[n][n]);
}
