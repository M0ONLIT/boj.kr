#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;

vector<int> input_vector(int n){
  vector<int> v(n);
  for(int i=0; i<n; i++)
    cin>>v[i];
  return v;
}

int n;
ll dp[10001][10001];
bool visit[10001][10001];
vector<int> ian, yehwan;

ll f(int index, int kill){
  if(index==n)
    return 0;
  if(visit[index][kill])
    return dp[index][kill];
  visit[index][kill]=1;

  ll ans;
  if(yehwan[index]<ian[index-kill])
    ans=f(index+1, kill)+100;
  else if(yehwan[index]==ian[index-kill])
    ans=max(f(index+1, kill)+20, f(index+1, kill+1)-50);
  else
    ans=f(index+1, kill+1)-50;
  //cout<<yehwan[index]<<' '<<ian[index-kill]<<' '<<index<<' '<<kill<<' '<<ans<<endl;
  return dp[index][kill]=ans;
}

int main(){
  ioset();
  cin>>n;
  ian=input_vector(n);
  yehwan=input_vector(n);

  sort(ian.rbegin(), ian.rend());
  sort(yehwan.rbegin(), yehwan.rend());
  cout<<f(0, 0);
}
