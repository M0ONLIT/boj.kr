#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>

using namespace std;
const int INF=10000;
int n;
int arr[105][105];
int mom[20][100005];
int mom_cost[20][100005];
int depth[100005];
int visit[100005];
vector<pair<int, int>> tree[100005];

void dfs(int Mom, int x, int d, int cost){
	if(visit[x]++)
	  return;

	mom[0][x]=Mom;
  mom_cost[0][x]=cost;
	depth[x]=d;
	for(pair<int, int> i: tree[x])
		dfs(x, i.first, d+1);
}

int upto(int x, int d){
	int i;
	if(d)
	  for(i=0; i<=log2(d); i++)
		  if(d&(1<<i))
			  x=mom[i][x];
	return x;
}

int setdepth(int x, int d){
	return upto(x, depth[x]-d);
}

int swap(int &a, int &b){
	a=a^b;
	b=a^b;
	a=a^b;
	return 0;
}

int lca(int x, int y){
	int i;
	depth[x]<depth[y]?swap(x,y):0;
	x=upto(x, depth[x]-depth[y]);

	if(x!=y){
	  for(i=(int)log2(depth[x])+1; i>=0; i--){
			if(mom[i][x]!=mom[i][y]){
				x=mom[i][x];
				y=mom[i][y];
			}
		}
		x=upto(x, 1);
	}
	return x;
}
int main(){
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL); cout.tie(NULL);
  int i, j, x, y, cost;

  cin>>n;
	for(i=0;i<n-1;i++){
		cin>>x>>y>>cost;
		tree[x].push_back({y, cost});
		tree[y].push_back({x, cost});
	}
	dfs(0, 1, 1, INF); //1의 depth: 1

	//mom[i][j] = upto 2**i from j
	for(i=1; i<=log2(n)+1; i++)
		for(j=1; j<=n; j++)
			mom[i][j]=mom[i-1][mom[i-1][j]];


}
