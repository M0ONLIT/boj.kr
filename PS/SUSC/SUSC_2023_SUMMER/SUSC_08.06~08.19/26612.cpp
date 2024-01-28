//26612
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int n, m, k, check;
int ptr=1;

class Lca{
public:
	int next[20][300005];
	int depth[300005];
	int visit[300005];

	void sparse_table(){
		int i, j;
		for(i=1; i<20; i++)
			for(j=1; j<=3*n; j++)
				next[i][j]=next[i-1][next[i-1][j]];
	}
	int upto(int x, int d){
		int i;
		if(d)
		  for(i=0; i<20; i++)
			  if(d&(1<<i))
				  x=next[i][x];
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
		depth[x]<depth[y]?swap(x, y):0;
		x=upto(x, depth[x]-depth[y]);

		if(x!=y){
		  for(i=19; i>=0; i--){
				if(next[i][x]!=next[i][y]){
					x=next[i][x];
					y=next[i][y];
				}
			}
			x=upto(x, 1);
		}
		return x;
	}
} LCA;

int Hash(int x, char c){
	return n*(c-'x')+x;
}

class Union_find{
public:
    vector<int> v;

    Union_find(int n){
    	v=vector<int>(n+1);
    	for(int i=0; i<=n; i++){
    		v[i]=i;
    	}
    }

    int up(int x){
    	if(v[x]==x)
    	    return x;
    	return v[x]=up(v[x]);
    }

    void merge(int x, int y){
    	v[up(x)]=up(y);
    }

    int equal(int x, int y){
    	return up(x)==up(y);
    }
} UNION(300005);

int dfs(int node, int start){
  if(node==0)
    return 0;
  if(LCA.visit[node]){
    if(LCA.visit[node]==ptr){
      check=1;
      return 0;
    }
    UNION.merge(node, start);
    return LCA.depth[node];
  }
  UNION.merge(node, start);
	LCA.visit[node]=ptr;
  return LCA.depth[node]=dfs(LCA.next[0][node], start)+1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int i, j, p, q, node1, node2, node3;
	char c;

	cin>>n>>m>>k;
	for(i=0; i<m; i++){
		cin>>p>>q>>c;
		LCA.next[0][Hash(p, c)]=Hash(q, (c=='z')?'x':(c+1));
	}
	for(i=1; i<=n; i++){
    for(c='x'; c<='z'; c++){
			if(!LCA.visit[Hash(i, c)]){
        dfs(Hash(i, c), Hash(i, c));
        ptr++;
			}
    }
  }

	LCA.sparse_table();

	for(i=0; i<k; i++){
		cin>>p>>q>>c;
		node1=Hash(q, (c=='z')?'x':(c+1));
		node2=Hash(p, c);
		if(check){
			cout<<1<<'\n';
		}
		else if(UNION.equal(node1, node2)){
			node3=LCA.lca(node1, node2);
			cout<<(node3==node2)<<'\n';
		}
		else{
			cout<<0<<'\n';
		}
	}
}
