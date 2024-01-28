#include<stdio.h>
#include<math.h>

const int MAX=pow(2, 15)+1;
int dp[MAX];

void f(int idx, int result, int cnt, int c){
  if(result>=MAX || cnt>4 || idx==0) return;
  if(cnt>0 && c) dp[result]++;

  f(idx, result+idx*idx, cnt+1, 1);
  f(idx-1, result, cnt, 0);
}

int main(){
  int x;

  f(181, 0, 0, 0);

  while(1){
    scanf("%d", &x);
    if(x) printf("%d\n", dp[x]);
    else break;
  }
}
