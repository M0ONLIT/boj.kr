#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
int arr[200005], big[200005], small[200005];
int main() {
  ioset();
  int i, j;
  cin>>n>>m;
  for(i=0; i<n; i++) cin>>arr[i];
  for(i=0; i<n; i++) small[i]=((i==0)?arr[i]:min(small[i-1], arr[i]));
  for(i=n-1; i>=0; i--) big[i]=((i==n-1)?arr[i]:max(big[i+1], arr[i]));

  int ans=-210000000;
  for(i=0; i<=m; i++){
    ans=max(ans, big[n-m+i-1]-small[i]);
  }
  cout<<ans;
}
