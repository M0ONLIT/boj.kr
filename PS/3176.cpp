#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
typedef long long ll;
const int inf=987654321;

int n,m;
int mom[20][100005];
int lgest[20][100005];
int stest[20][100005];
int depth[100005];
int visit[100005];
vector<pair<int, int>> tree[100005];

void dfs(int Mom, int x, int dep, int dis){
	if(visit[x]++)
	  return;

	mom[0][x]=Mom;
	lgest[0][x]=stest[0][x]=dis;
	depth[x]=dep;
	for(pair<int, int> i: tree[x])
		dfs(x, i.first, dep+1, i.second);
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

int upto_st(int x, int d){
	int i, st=inf;
	if(d)
	  for(i=0; i<=log2(d); i++)
		  if(d&(1<<i)){
			  st=min(st, stest[i][x]);
			  x=mom[i][x];
		  }
	return st;
}

int upto_lg(int x, int d){
	int i, lg=0;
	if(d)
	  for(i=0; i<=log2(d); i++)
		  if(d&(1<<i)){
			  lg=max(lg, lgest[i][x]);
			  x=mom[i][x];
		  }
	return lg;
}

int main(){
	int i, j, x, y, d;
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(i=0;i<n-1;i++){
		cin>>x>>y>>d;
		tree[x].push_back({y, d});
		tree[y].push_back({x, d});
	}
	dfs(0, 1, 1, 0); //1의 depth: 0

	//mom[i][j] = upto 2**i from j
	for(i=1; i<=log2(n)+1; i++)
		for(j=1; j<=n; j++){
			mom[i][j]=mom[i-1][mom[i-1][j]];
			lgest[i][j]=max(lgest[i-1][j], lgest[i-1][mom[i-1][j]]);
			stest[i][j]=min(stest[i-1][j], stest[i-1][mom[i-1][j]]);
		}
	cin>>m;
	for(i=0;i<m;i++){
	    int st, lg, LCA;
		cin>>x>>y;
		LCA=lca(x, y);
		st=min(upto_st(x, depth[x]-depth[LCA]), upto_st(y, depth[y]-depth[LCA]));
		lg=max(upto_lg(x, depth[x]-depth[LCA]), upto_lg(y, depth[y]-depth[LCA]));
		cout<<st<<' '<<lg<<'\n';
	}
}
