#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<deque>
#include<map>
#include<set>
#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;

int dfs(int node, vector<int>& visit, vector<vector<int>>& graph){
    if(visit[node]++) return 0;
    int ans=1;
    for(int nxt: graph[node]){
        ans+=dfs(nxt, visit, graph);
    }
    return ans;
}

int main(int argc, char** argv){
    ioset();
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++) {
        int n; cin>>n;
        vector<vector<int>> graph(n+1);
        vector<int> point, visit(n+1);
        ll ans=0;
        for(int i=0; i<n+1; i++){
            int x, y; cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        for(int i=1; i<=n; i++) if(graph[i].size()==3){
            point.push_back(i);
            visit[i]=1;
        }
        for(int i: graph[point[0]]){
            if(i!=point[1]){
                ll k=dfs(i, visit, graph)+1;
                ans+=k*(k-1)/2;
            }
        }
		cout << "Case #" << test_case+1 << endl;
		cout << ans << endl;
	}

	return 0;
}
