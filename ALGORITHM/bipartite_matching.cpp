// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm> //fill(v.begin(), v.end(), 0);
#include <vector>
#include <memory.h>
using namespace std;

int n, m, ans;
vector<int> arr[1005];
int memory[1005];
int match[1005];

int dfs(int x){
  for(int i: arr[x]){
    if(memory[i])
      continue;

    memory[i]=1;
    if(match[i]==0 || dfs(match[i])){ //match[i]는 그룹 i번에서 연결된 x(사람)을 의미함.
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
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>p;
        for(int j=0; j<p; j++){
            cin>>q;
            arr[i].push_back(q);
        }
    }
    for(int i=1; i<=n; i++){
        fill(memory, memory+1005, 0);
        ans+=dfs(i);
    }
    cout<<ans;
    return 0;
}
