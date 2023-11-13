#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

typedef long long ll;
ll L, R;
int dp[18][1<<10][2520]; //자릿수, 어떤 수 썼는지 비트, 나머지, iszero
bool visit[18][1<<10][2520];
int l[20], r[20], mod[18][10]; //pow, n

void write(int x[], int k){
  int ptr=0;
  while(k!=0){
    x[ptr++]=k%10;
    k/=10;
  }
}

//iszero는 0일때 0만 사용, 1은 있
//big=1일때 클수도 있음
int ww(int idx, int bit, int k, int arr[], int big){
  if(idx<0){
    for(int o=1; o<10; o++){
      if(((bit>>o) & 1) && k%o!=0)
        return 0;
    }
    return 1;
  }
  if(visit[idx][bit][k])
    return dp[idx][bit][k];
  visit[idx][bit][k]=1;
  for(int o=0; o<10; o++){
    if(o==0 && (bit&1)) continue
  }
}

int main(){
  ioset();
  int i, j;
  for(i=0; i<18; i++)
    for(j=1; j<10; j++)
      if(i==0) mod[0][j]=j;
      else mod[i][j]=mod[i-1][j]*10%2520;
  cin>>L>>R;
  write(l, L-1);
  write(r, R);
}
