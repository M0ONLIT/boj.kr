#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<memory.h>

typedef long long ll;
using namespace std;

int r, c, n, check[305], connect[305];
int arr[305][305];

vector<int> tree[305];

int dfs(int x){
  for(int i: tree[x]){
    if(check[i])
      continue;
    check[i]=1;
    if(connect[i]==0 || dfs(connect[i])){
      connect[i]=x;
      return 1;
    }
  }
  return 0;
}

int main(){
  int i, j, p, q;
  scanf("%d%d%d", &r, &c, &n);
  for(i=0; i<n; i++){
    scanf("%d%d", &p, &q);
    arr[p][q]=1;
  }

  for(i=1; i<=r; i++)
    for(j=1; j<=c; j++)
      if(!arr[i][j])
        tree[i].push_back(j);

  int count=0;
  for(i=1; i<=r; i++){
    fill(check, check+301, 0);
    count+=dfs(i);
  }
  printf("%d", count);
}
