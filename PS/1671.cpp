#include<iostream>
#include<vector>
#include<algorithm>
#define FOR(i, n) for(int i=1; i<=n; i++)
#define endl '\n'
#define ioset() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define std using namespace std
std;
typedef long long ll;
int match[55], memory[55];
int state[55][3];
vector<int> shark[105];

int compare(int x, int y){
    int *p=state[x], *q=state[y];
    FOR(i, 3)
        if(p[i-1]<q[i-1])
            return 0;
    FOR(i, 3)
        if(p[i-1]!=q[i-1])
            return 1;
    return x<y;
}

int dfs(int x){
    for(int i: shark[x]){
        if(memory[i])
            continue;
        memory[i]=1;
        
        if(match[i]==0 || dfs(match[i])){
            match[i]=x;
            return 1;
        }
    }
    return 0;
}

int n, p, q, ans;
int main(){
	ioset();
	cin>>n;
	FOR(i, n){
	    cin>>state[i][0]>>state[i][1]>>state[i][2];
	}
	FOR(i, n) FOR(j, n){
	    if(i==j) continue;
	    if(compare(i, j)){
	        shark[i*2-1].push_back(j);
	        shark[i*2].push_back(j);
	    }
	}
	FOR(i, 2*n){
	    fill(memory, memory+55, 0);
	    dfs(i);
	}
	FOR(i, n){
	    //cout<<match[i]<<' ';
	    ans+=(match[i]==0);
	}
	cout<<ans;
}
