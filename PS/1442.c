#include<stdio.h>

typedef long long ll;
int L, R;
ll dp[40][2][6];
int visit[40][2][6];
/*
0이 1스택: 1
1이 1스택: 2
0이 2스택: 3
1이 2스택: 4
complete: 5
*/
ll max(ll a, ll b){
    return a>b?a:b;
}

ll f(int index, int iszero, int stack){ //iszero는 1이 나오는 순간부터 1
  if(visit[index][iszero][stack])
    return dp[index][iszero][stack];
  visit[index][iszero][stack]=1;
  if(index==0) return dp[index][iszero][stack]=(iszero && (stack==5));
  else if(iszero==0) return dp[index][iszero][stack]=(f(index-1, 1, 2)+f(index-1, 0, 0));
  else{
    if(stack==5)
      return dp[index][iszero][stack]=(f(index-1, 1, 5)+f(index-1, 1, 5));
    else if(stack<=2)
      return dp[index][iszero][stack]=(f(index-1, 1, stack%2+1)+f(index-1, 1, stack+2));
    else if(stack<=4)
      return dp[index][iszero][stack]=(f(index-1, 1, 5-stack)+f(index-1, 1, 5));
  }
}

ll find(ll x){
  ll index, ans=0;
  int iszero=0, stack=0;
  for(index=31; index>=0; index--){
    if(x & (1LL<<index)){
      if(iszero==0){
        ans+=dp[index][0][0];
        iszero=1;
        stack=2;
      }
      else if(stack==1){
        ans+=dp[index][1][3];
        stack=2;
      }
      else if(stack==2){
        ans+=dp[index][1][1];
        stack=4;
      }
      else if(stack==3){
        ans+=dp[index][1][5];
        stack=2;
      }
      else if(stack==4){
        ans+=dp[index][1][1];
        stack=5;
      }
      else if(stack==5){
        ans+=dp[index][1][5];
      }
    }
    else{
      if(iszero==0);
      else if(stack==1){
        stack=3;
      }
      else if(stack==2){
        stack=1;
      }
      else if(stack==3){
        stack=5;
      }
      else if(stack==4){
        stack=1;
      }
      else if(stack==5);
    }
  }
  ans+=dp[0][iszero][stack];

  return ans;
}


int main(){
  scanf("%d%d", &L, &R);
  f(31, 0, 0);
  printf("%d",find(R)-find(max(L-1, 0)));
}
