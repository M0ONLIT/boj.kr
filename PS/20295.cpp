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
int shop[20][100005];
int depth[100005];
int visit[100005];
int candy[100005];
vector<int> tree[100005];

void dfs(int Mom, int x, int dep){
    if(visit[x]++)
      return;

    mom[0][x]=Mom;
    shop[0][x]=candy[x];
    depth[x]=dep;
    for(int i: tree[x])
        dfs(x, i, dep+1);
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

int upto_c(int x, int d){
    int i, c=0;
    if(d)
      for(i=0; i<=log2(d); i++)
          if(d&(1<<i)){
              c|=shop[i][x];
              x=mom[i][x];
          }
    return c;
}

int main(){
    int i, j, x, y, k, now, check=0, t=0;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(i=1; i<=n; i++){
        cin>>k;
        candy[i]=1<<k;
        check|=(1<<k);
    }
    for(i=0; i<n-1; i++){
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(0, 1, 1); //1의 depth: 1

    //mom[i][j] = upto 2**i from j
    for(i=1; i<=log2(n)+1; i++)
        for(j=1; j<=n; j++){
            mom[i][j]=mom[i-1][mom[i-1][j]];
            shop[i][j]=shop[i-1][j] | shop[i-1][mom[i-1][j]];
        }
    cin>>m;
    for(i=0;i<m;i++){
        int LCA;
        cin>>x>>y;
        if(t==0){
            if((check & (1<<y))==0)
                cout<<"CRY\n";
            else{
                cout<<"PLAY\n";
                now=x; t=1;
            }
            continue;
        }
        LCA=lca(now, x);
        int p=upto_c(now, depth[now]-depth[LCA]) | upto_c(x, depth[x]-depth[LCA]) | candy[LCA];

        if((p & (1<<y))==0)
            cout<<"CRY\n";
        else
            cout<<"PLAY\n";
        now=x;
    }
}
