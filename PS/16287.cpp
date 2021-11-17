#include<stdio.h>
#include<vector>
using namespace std;
int arr[5005];
int visit[4][800000]; //0~3
vector<int> vec[4];

int w, n;
int main(){
  int i, j;

  scanf("%d%d", &w, &n);
  for(i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }

  for(i=0; i<n; i++){
    for(j=0; j<4 && j<=i; j++){
      if(j==0){
        visit[0][arr[i]]=1;
        vec[0].push_back(arr[i]);
        continue;
      }
      for(int k: vec[j-1]){
        if(k+arr[i]<=w && visit[j][k+arr[i]]==0){
          visit[j][k+arr[i]]=1;
          vec[j].push_back(k+arr[i]);
        }
      }
    }
  }

  for(i=0; i<4; i++){
    for(int j: vec[i])
      printf("%d ", j);
    printf("\n");
  }
  printf(visit[3][w]?"YES":"NO");

}
