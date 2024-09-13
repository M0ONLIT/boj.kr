#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<deque>
#include<memory.h>
#include<cassert>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> iii;

const int mx=1010;
const int po=21;
int n, m, ptr;
int arr[mx][mx], depth[mx][mx], visit[mx][mx], vertex[mx][mx];
vector<iii> v;
vector<iii> tree[mx][mx];
int mom[po][mx*mx];
deque<iii> Q;
vector<pair<int, int>> nearby8(int y, int x, int r = n+1, int c = n+1) {
    int dy[] = {-1, 0, 1};
    int dx[] = {-1, 0, 1};
    vector<pii> ans;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == 1 && j == 1) {
                continue;
            }
            int ny = y + dy[i];
            int nx = x + dx[j];
            if (0 <= ny && ny <= r && 0 <= nx && nx <= c) {
                ans.emplace_back(ny, nx);
            }
        }
    }
    return ans;
}

vector<pair<int, int>> nearby4(int y, int x, int r = n+1, int c = n+1) {
    int dy[] = {0, 0, 1, -1};
    int dx[] = {1, -1, 0, 0};
    vector<pii> ans;
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (0 <= ny && ny <= r && 0 <= nx && nx <= c) {
            ans.emplace_back(ny, nx);
        }
    }
    return ans;
}

int upto(int x, int d){
	int i;
	if(d)
	  for(i=0; i<po; i++)
		  if(d&(1<<i))
			  x=mom[i][x];
	return x;
}

int lca(int x, int y, int d1, int d2){
	int i;
	if(d1<d2){swap(d1, d2); swap(x, y);}
	x=upto(x, d1-d2);

    int ans=d2;
	if(x!=y){
	    for(i=po-1; i>=0; i--){
			if(mom[i][x]!=mom[i][y]){
				x=mom[i][x];
				y=mom[i][y];
                ans-=(1<<i);
			}
		}
		x=upto(x, 1);
        ans--;
	}
	return ans;
}

void print_arr(int arr[mx+1][mx+1]){
    int i, j;
    for(i=0; i<=n+1; i++){
        for(j=0; j<=n+1; j++)
            cout<<arr[i][j];
        cout<<'\n';
    } cout<<'\n';
}

int main(){
    ioset();
    int i, j;
    cin>>n;
    for(i=1; i<=n; i++) for(j=1; j<=n; j++){
        char x; cin>>x;
        if(x=='.') arr[i][j]=1;
    }
    for(i=0; i<=n+1; i++) for(j=0; j<=n+1; j++)
        if(arr[i][j]==0)
            Q.push_back({i, j, 0});

    while(!Q.empty()){
        int i, j, d; tie(i, j, d)=Q.front(); Q.pop_front();
        if(visit[i][j]++) continue;
        depth[i][j]=d;
        for(pii p: nearby8(i, j))
            Q.push_back({p.first, p.second, d+1});
    }

    for(i=0; i<=n+1; i++) for(j=0; j<=n+1; j++){
        for(pii pi: nearby4(i, j)){
            int p, q; tie(p, q)=pi;
            v.push_back({p, q, min(depth[i][j], depth[p][q])});
        }
    }

    sort(v.begin(), v.end(), [](iii x, iii y){
        return get<2>(x)<get<2>(y);
    });
    for(iii t: v){

    }



	for(i=1; i<po; i++)
		for(j=0; j<=ptr; j++)
			mom[i][j]=mom[i-1][mom[i-1][j]];

    cin>>m;
    while(m--){
        int y1, x1, y2, x2, d1, d2, v1, v2;
        cin>>y1>>x1>>y2>>x2;
        d1=depth[y1][x1]; d2=depth[y2][x2];
        v1=vertex[y1][x1]; v2=vertex[y2][x2];
        cout<<max(2*lca(v1, v2, d1, d2)-1, 0)<<'\n';
    }
}
