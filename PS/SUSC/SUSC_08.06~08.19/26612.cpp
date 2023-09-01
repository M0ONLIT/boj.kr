//26612
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, k, check;
int Next[300005], visit[300005], ptr=1;

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

void dfs(int node, int start){
  if(node==0)
    return;
  if(visit[node]){
    if(visit[node]==ptr){
      check=1;
      return;
    }
    UNION.merge(node, start);
    return;
  }
  UNION.merge(node, start);
	visit[node]=ptr;
  dfs(Next[node], start);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int i, j, p, q, r;
	char c;

	cin>>n>>m>>k;
	for(i=0; i<m; i++){
		cin>>p>>q>>c;
		Next[Hash(p, c)]=Hash(q, c=='z'?'x':c+1);
	}
	for(i=1; i<=n; i++){
    for(c='x'; c<='z'; c++){
      dfs(Hash(i, c), Hash(i, c));
      ptr++;
    }
  }
	for(i=0; i<k; i++){
		cin>>p>>q>>c;
		if(check || UNION.equal(Hash(q, c=='z'?'x':c+1), Hash(p, c))){
			cout<<1<<'\n'<<UNION.equal(Hash(2, 'y'), Hash('1', 'x'));
		}
		else{
			cout<<0<<'\n';
		}
	}
}
