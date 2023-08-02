#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll n;
ll seven_mod[21], two_mod[21];
int dp[500005];
int value[500005];
int d[500005];

void push(int num, int index, int prev, int digit){
  if(dp[index]) return;
  dp[index]=num;
  value[index]=prev; //prev는 전 index
  d[index]=digit;
}

int main(){
  int i, j;
  cin>>n;
  for(i=0; i<=20; i++){
    if(i==0){
      seven_mod[i]=7%n;
      two_mod[i]=2%n;
      continue;
    }
    seven_mod[i]=10*seven_mod[i-1]%n;
    two_mod[i]=10*two_mod[i-1]%n;
  }


  push(2, two_mod[0], -1, 0);
  push(7, seven_mod[0], -1, 0); // k면 -k-1개 0을 출력
  for(i=1; i<20; i++){
    push(2, two_mod[i], -1, i);
    push(7, seven_mod[i], -1, i); // k면 -k-1개 0을 출력
    for(j=0; j<n; j++)
      if(dp[j] && d[j]<i)
        push(2, (two_mod[i]+j)%n, j, i);
    for(j=0; j<n; j++)
      if(dp[j] && d[j]<i)
        push(7, (seven_mod[i]+j)%n, j, i);
  }

  if(!dp[0]){
    cout<<"NAV";
    return 0;
  }

  for(i=0; ; i=value[i]){
    cout<<dp[i];
    if(value[i]==-1){
      for(j=0; j<d[i]; j++)
        cout<<0;
      break;
    }

    for(j=0; j<d[i]-d[value[i]]-1; j++)
      cout<<0;
  }
}
