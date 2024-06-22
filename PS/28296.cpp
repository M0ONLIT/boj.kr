#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
#include<map>
#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> iii;
const int inf=2100000000;
const int mx=100005;
//union find, maximum spanning tree, small to large
int n, k, m;
int c[mx];
vector<iii> edge;

class UnionFind {
public:
    vector<int> parent;
    vector<int> size;
    vector<ll> ans;
    vector<map<int, int>> info; //map<int, int>는 회사, 개수
    UnionFind(int n) {
        parent.resize(n);
        info.resize(n);
        ans.resize(k+1);
        for (int i = 0; i < n; ++i){
            parent[i] = i;
            info[i][c[i]]++;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void sum(int x, int y, int w) {
        //if (x>=n || y>=n) return; //범위체크
        int root_x = find(x);
        int root_y = find(y);

        if (root_x != root_y) {
            if (info[root_x].size() < info[root_y].size()) {
                parent[root_x] = root_y;
                mergeMaps(info[root_x], info[root_y], w);
            } else {
                parent[root_y] = root_x;
                mergeMaps(info[root_y], info[root_x], w);
            }
        }
    }

    bool equal(int x, int y) {
        return find(x) == find(y);
    }

    int count(int x) {
        int root = find(x);
        return size[root];
    }

    void mergeMaps(map<int, int>& a, map<int, int>& b, int w) {
        for (const auto& [key, value] : a) {
            b[key] += value;
            ans[key] += (ll)(b[key]-value)*value*w;
        }
        a.clear();
    }
};
int main(){
    ioset();
    int i, j;
    cin>>n>>k>>m;
    edge.resize(m);
    for(i=1; i<=n; i++) cin>>c[i];
    for(i=0; i<m; i++){
        int x, y, w; cin>>x>>y>>w;
        edge[i]=make_tuple(-w, x, y);
    } sort(edge.begin(), edge.end());

    UnionFind uf(mx);
    for(auto [w, x, y]: edge){
        w=-w;
        uf.sum(x, y, w);
    }
    for(i=1; i<=k; i++) cout<<uf.ans[i]<<'\n';
}
