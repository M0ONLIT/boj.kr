#include<iostream>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;

int n,m;
int mom[20][100005];
int depth[100005];
int visit[100005];
int root_dis[100005];
map<pair<int, int>, int> dis;
vector<int> tree[100005];

void dfs(int Mom, int x, int d, int distance){
	if(visit[x]++)
	  return;

	mom[0][x]=Mom;
	depth[x]=d;
	root_dis[x]=distance;
	for(int i: tree[x])
		dfs(x, i, d+1, distance+dis[{x, i}]);
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
	int i,j,x,y,d;
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(i=0;i<n-1;i++){
		cin>>x>>y>>d;
		tree[x].push_back(y);
		tree[y].push_back(x);
		dis[{x, y}]=dis[{y, x}]=d;
	}
	dfs(0, 1, 1, 0); //1의 depth: 0

	//mom[i][j] = upto 2**i from j
	for(i=1; i<=log2(n)+1; i++)
		for(j=1; j<=n; j++)
			mom[i][j]= mom[i-1][mom[i-1][j]];

	cin>>m;
	for(i=0;i<m;i++){
		cin>>x>>y;
		cout<<root_dis[x]+root_dis[y]-2*root_dis[lca(x,y)]<<'\n';

	}
}
//11438 변형
