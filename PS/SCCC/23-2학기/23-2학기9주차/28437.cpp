#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
const int mx=100001;
int n, q, a[mx], i, j, x;

int main(){
  ioset();
  cin>>n;
  for(i=0; i<n; i++){
    cin>>x;
    a[x]=1;
  }
  for(i=1; i<mx; i++)
    if(a[i])
      for(j=2; i*j<mx; j++)
        a[i*j]+=a[i];
  cin>>q;
  while(q--){
    cin>>x;
    cout<<a[x]<<' ';
  }
}
