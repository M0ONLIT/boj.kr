#include <iostream>
#include <vector>
#include <queue>
#define mx 100005

using namespace std;

int n, m, k;
vector<pair<int, int>> graph[mx];
bool visit[mx][12];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q; // (dist, node)
    Q.push({0, 1});

    while (!Q.empty()) {
        int dis = Q.top().first;
        int node = Q.top().second;
        Q.pop();

        int mod = dis % 12;

        if (dis > k || visit[node][mod])
            continue;

        visit[node][mod] = true;

        if (node == n && k % 12 == mod)
            break;

        for (auto i : graph[node]) {
            int nxt = i.first;
            int d = i.second;
            Q.push({dis + d, nxt});
        }
    }

    if (visit[n][k % 12])
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
