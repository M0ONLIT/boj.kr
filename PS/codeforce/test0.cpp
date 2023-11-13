#include<cstdio>
#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

typedef long long ll;
string L, R;
int mod[18][10], l[20], r[20]; //pow, n

void write(int x[], string k){
  for(int i=0; i<k.size(); i++){
    x[i]=k[k.size()-i-1]-'0';
  }
}
int main(){
  int i, j;
  for(i=0; i<18; i++)
    for(j=1; j<10; j++)
      if(i==0) mod[0][j]=j;
      else mod[i][j]=mod[i-1][j]*10%2520;
  cin>>L>>R;
  write(l, L);
  write(r, R);
  cout<<"no bug";
}
