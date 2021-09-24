#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;

int n,m;
int mom[20][100005];
int depth[100005];
int visit[100005];
vector<int> tree[100005];

void dfs(int Mom, int x, int d){
	if(visit[x]++)
	  return;

	mom[0][x]=Mom;
	depth[x]=d;
	for(int i: tree[x])
		dfs(x, i, d+1);
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
	int i,j,r,x,y;
	cout<<sizeof(a);
	/*
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
*/
	cin>>n;
	for(i=0;i<n-1;i++){
		cin>>x>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	dfs(0, 1, 1); //1의 depth: 1

	//mom[i][j] = upto 2**i from j
	for(i=1; i<=log2(n)+1; i++)
		for(j=1; j<=n; j++)
			mom[i][j]= mom[i-1][mom[i-1][j]];

	cin>>m;
	for(i=0;i<m;i++){
		int o, p, q, ans;
		cin>>r>>x>>y;
		o=lca(x,y);
		p=lca(r,x);
		q=lca(r,y);

		ans=o;
		if(depth[ans]<depth[p]) ans=p;
		if(depth[ans]<depth[q]) ans=q;
		cout<<ans<<'\n';

	}
}
