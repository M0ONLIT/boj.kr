#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N,M,K,arr[101010],sum[101010],a,b,cur;
set<int> ans;
bool c[101010];
ll D[105050];
vector<ll> G[105050];

void dik(int s){
    memset(D, 0x3f, sizeof D);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>> Q;
    Q.push({arr[1],1});
    Q.emplace(D[s]=arr[s], s);
    while(!Q.empty()){
        auto [c,v] = Q.top(); Q.pop();
        if(c == D[v]) for(auto i : G[v]) if(D[i] > c + arr[i]) Q.emplace(D[i]=c+arr[i],i);
    }
}

int VISIT[200005];
void DFS(int node){
    if(VISIT[node]++) return;

    ans.push_back(node);
    for(int nxt : G[node]){
        if(D[node] - arr[node] == D[nxt]){
            DFS(nxt);
        }
    }
}

void print_state(){
    for(int i=1; i<=N; i++) cout<<arr[i]<<' ';
    cout<<'\n';
    for(int i=1; i<=N; i++) cout<<D[i]<<' ';
    cout<<'\n';
    for(int i: ans) cout<<i<<' ';
    cout<<'\n';
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    for(int i = 1;i<=N;i++) cin >> arr[i];
    while(M--){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    fill(sum+1,sum+N+1,INT_MAX);
    dik(1);
    DFS(N);
    print_state();
    if(K > N-K){
        if(ans.size()+1 <= K){
            c[N] = 1;
            for(int i : ans) c[i] = 1;
            int tmp = 0;
            for(int i = 1;i<=N;i++){
                if(c[i]) cout << "N";
                else if(tmp + ans.size() + 1 < K){
                    cout << "N";
                    tmp++;
                }
                else cout << "S";
            }
        }
        else cout << "impossible";
    }
    else{
        if(ans.size()+1 <= N-K){
            c[N] = 1;
            for(int i : ans) c[i] = 1;
            int tmp = 0;
            for(int i = 1;i<=N;i++){
                if(c[i]) cout << "S";
                else if(tmp + ans.size() + 1 < N - K){
                    cout << "S";
                    tmp++;
                }
                else cout << "N";
            }
        }
        else cout << "impossible";
    }
}
