#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<memory.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

//const ll inf=(1LL<<63)-1;


int arr[105][105];
int cpy[105][105];
int ans;

void push(int i, int j, int (*arr)[105]){
  arr[i][j]=!arr[i][j];
  arr[i-1][j]=!arr[i-1][j];
  arr[i+1][j]=!arr[i+1][j];
  arr[i][j+1]=!arr[i][j+1];
  arr[i][j-1]=!arr[i][j-1];
  ans++;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int i, j, bit;
  char x;
  for(i=1; i<=10; i++)
    for(j=1; j<=10; j++){
      cin>>x;
      arr[i][j]=x=='O';
    }
  for(bit=0; bit<(1<<10); bit++){
    ans=0;
    memcpy(cpy, arr, sizeof arr);
    for(i=0; i<10; i++)
      if((1<<i)&bit)
        push(1, i+1, cpy);

    for(i=2; i<=10; i++)
      for(j=1; j<=10; j++)
        if(cpy[i-1][j])
          push(i, j, cpy);

    j=0;
    for(i=1; i<=10; i++)
      j+=cpy[10][i];

    if(j==0){
      cout<<ans;
      return 0;
    }
  }
  cout<<-1;
}
