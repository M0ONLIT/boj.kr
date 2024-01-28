#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

vector<vector<pair<int, int>>> input_graph(int n, int m) {
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    return graph;
}

int d(int node, vector<int>& friend_list, const vector<vector<pair<int, int>>>& graph) {
    int ans = 0;
    vector<int> visit(graph.size(), 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({0, node});

    while (!Q.empty()) {
        int dis = Q.top().first;
        int node = Q.top().second;
        Q.pop();
        if (visit[node]) {
            continue;
        }
        visit[node] = 1;

        if (friend_list[node]) {
            ans += dis;
        }
        for (const auto& [nxt, d_nxt] : graph[node]) {
            if (!visit[nxt]) {
                Q.push({dis + d_nxt, nxt});
            }
        }
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> friend_list(n + 1, 0);
    auto graph = input_graph(n, m);
    int f;
    cin >> f;
    for (int i = 0; i < f; i++) {
        int friend_node;
        cin >> friend_node;
        friend_list[friend_node] = 1;
    }

    int ans_node, ans_dis = INF;
    for (int node = 1; node <= n; node++) {
        int distance = d(node, friend_list, graph);
        if (distance < ans_dis) {
            ans_dis = distance;
            ans_node = node;
        }
    }

    cout << ans_node << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
