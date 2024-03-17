#include <iostream>
#include <algorithm> //fill(v.begin(), v.end(), 0);
#include <vector>
#include <memory.h>
using namespace std;

int n, k, x;
vector<int> arr[1005], ans[1005];
vector<pair<int, int>> stu;
int memory[1005];
int match[1005];

int dfs(int x){
  for(int i: arr[x]){
    if(memory[i])
      continue;

    memory[i]=1;
    if(match[i]==0 || dfs(match[i])){
      match[i]=x;
      return 1;
    }
  }
  return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int p, q;
    cin>>n>>k>>x;
    for(int i=1; i<=n; i++){
        cin>>p;
        for(int j=0; j<p; j++){
            cin>>q;
            for(int l=0; l<x; l++){
                arr[i].push_back(q*x+l);
            }
        }
    }
    for(int i=1; i<=n; i++){
        int r;
        cin>>r;
        stu.emplace_back(-r, i);
    }
    sort(stu.begin(), stu.end());
    for(auto i: stu){
        fill(memory, memory+1005, 0);
        dfs(i.second);
    }
    for(int i=1; i<=k; i++){
        for(int l=0; l<x; l++){
            if(match[i*x+l]!=0){
                ans[i].push_back(match[i*x+l]);
            }
        }
    }
    for(int i=1; i<=k; i++){
        cout<<ans[i].size()<<' ';
        for(int j: ans[i])
            cout<<j<<' ';
        cout<<'\n';
    }
    return 0;
}
