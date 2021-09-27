#include<vector>
#include<iostream>
using namespace std;

int n, ans;
bool visit[1000005];
vector<int> vec[1000005];

int dfs(int x){
  visit[x]=true;

  int count=0;
  int real=1;
  for(int i: vec[x]){
    if(!visit[i]){
      real&=dfs(i);
      count++;
    }
  }
  if(count==0)
    return 0;
  if(!real==1)
    ans++;
  return !real;
}

int main(){
  ios_base::sync_with_stdio(NULL);
  cin.tie(0); cout.tie(0);

  int i, j;
  cin>>n;
  for(i=0; i<n-1; i++){
    int p, q;
    cin>>p>>q;
    vec[p].push_back(q);
    vec[q].push_back(p);
  }

  dfs(1);
  cout<<ans;
}
