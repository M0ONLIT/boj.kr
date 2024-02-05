#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int mx=4000005;
int n, m, k, temp=-1;
int check[mx];

class UnionFind {
public:
    vector<int> parent;

    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void sum(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);

        if (root_x < root_y)
            parent[root_x] = root_y;
        else
            parent[root_y] = root_x;
    }

    bool equal(int x, int y) {
        return find(x) == find(y);
    }
};


int main() {
    ioset();
    int i, x, ans;
    cin>>n>>m>>k;
    UnionFind uf(n+5);

    for(i=0; i<m; i++){
        cin>>x;
        check[x]=1;
    }
    for(i=n+1; i>=0; i--){
        if(!check[i]){
            if(temp==-1) temp=i;
            else uf.parent[i]=temp;
        }
        else temp=-1;
    }
    for(i=0; i<k; i++){
        cin>>x;
        if(check[x+1]) ans=x+1;
        else ans=uf.find(x+1)+1;

        check[ans]=0;
        if(check[ans-1]==0) uf.sum(ans-1, ans);
        if(check[ans+1]==0) uf.sum(ans+1, ans);
        cout<<ans<<'\n';
    }
}
