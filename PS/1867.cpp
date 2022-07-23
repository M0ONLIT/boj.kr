// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm> //fill(v.begin(), v.end(), 0);
#include <vector>
#include <memory.h>
using namespace std;

int n, k, ans;
vector<int> people[1005];
int memory[1005];
int match[1005];

int dfs(int x){
  for(int i: people[x]){
    if(memory[i])
      continue;

    memory[i]=1;
    if(match[i]==0 || dfs(match[i])){
      match[i]=x;
      //cout<<x<<' '<<i<<endl;
      return 1;
    }
  }
  return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int p, q;
    cin>>n>>k;
    for(int i=1; i<=k; i++){
        cin>>p>>q;
        people[p].push_back(q);
    }
    for(int i=1; i<=n; i++){
        fill(memory, memory+1005, 0);
        ans+=dfs(i);
    }
    cout<<ans;
    return 0;
}
