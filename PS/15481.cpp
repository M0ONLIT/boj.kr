#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
typedef tuple<int, int, int, int> edge;
typedef long long ll;
const ll inf=9876543210;
const int mx=200005;

int v, e;
int mom[25][mx];
int maxi[25][mx];
int depth[mx];
int visit[mx];
int union_find[mx];
ll ans[mx];
ll s;
vector<pair<int, int>> tree[mx];
vector<edge> edges;

int u(int x){
    if(x==union_find[x])
        return x;
    return union_find[x]=u(union_find[x]);
}

int compare(edge x, edge y){
    return get<2>(x)<get<2>(y);
}

void dfs(int Mom, int x, int d, int dis){
	if(visit[x]++)
	  return;

	mom[0][x]=Mom;
	maxi[0][x]=dis;
	depth[x]=d;
	for(auto i: tree[x])
		dfs(x, i.first, d+1, i.second);
}

int upto(int x, int d){
	int i;
	if(d)
	  for(i=0; i<=log2(d)+1; i++)
		  if(d&(1<<i))
			  x=mom[i][x];
	return x;
}

ll upto_maxi(int x, int d){
	int i;
	ll ans=-inf;
	if(d)
	  for(i=0; i<=log2(d)+1; i++)
		  if(d&(1<<i)){
		      ans=max(ans, (ll)maxi[i][x]);
			  x=mom[i][x];
		  }
	return ans;
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
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int i, j, x, y, d, idx;

	cin>>v>>e;
	for(i=1; i<=v; i++)
	    union_find[i]=i;
	for(i=0; i<e; i++){
		cin>>x>>y>>d;
		edges.push_back({x, y, d, i});
	}
	sort(edges.begin(), edges.end(), compare);

	for(edge i: edges){
		tie(x, y, d, idx)=i;
		if(u(x)!=u(y)){
		    union_find[u(x)]=u(y);
		    tree[x].push_back({y, d});
		    tree[y].push_back({x, d});
		    s+=d;
		}
	}
	dfs(0, 1, 1, 0); //1의 depth: 1

	//mom[i][j] = upto 2**i from j
	for(i=1; i<=log2(v)+1; i++)
		for(j=1; j<=v; j++){
			mom[i][j]=mom[i-1][mom[i-1][j]];
			maxi[i][j]=max(maxi[i-1][j], maxi[i-1][mom[i-1][j]]);
		}

	for(edge i: edges){
		tie(x, y, d, idx)=i;
		int LCA=lca(x, y);
		ll maximum=max(upto_maxi(x, depth[x]-depth[LCA]), upto_maxi(y, depth[y]-depth[LCA]));
		ans[idx]=s-maximum+d;
	}
	for(i=0; i<e; i++)
    cout<<ans[i]<<'\n';
}
