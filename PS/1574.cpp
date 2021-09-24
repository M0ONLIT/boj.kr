#include<iostream>
#include<algorithm>
#include<cmath>
#include<memory.h>

typedef long long ll;
using namespace std;

int n, check[105], connect[105];
int arr[105][105];

vector<int> tree[105];

int dfs(int x){
  for(int i: tree[x]){
    check[i]=1;
    if(connect[i]==0 || dfs(connect[i])){
      connect[i]=x;
      return 1;
    }
  }
  return 0;
}

int main(){
  int i,j;
  char c;
  scanf("%d", &n);
  for(i=1; i<=n; i++){
    for(j=1; j<=n; j++){
      scanf("%c", &c);
      if(c=='.'){
        arr[i][j]=1;
        tree[i].push_back(j);
      }
    }scanf("%*c");
  }

  int count=0;
  for(i=1; i<=n; i++){
    fill(check, check+101, 0);
    count+=dfs(i);
  }
  printf("%d", count);
}
