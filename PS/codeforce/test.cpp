#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// 그래프의 정점 수
const int MAX_V = 1005;

// 다익스트라 알고리즘 함수
int dijkstra(int s, int e, int k, vector<vector<int>>& graph) {
    vector<int> dist(MAX_V, INT_MAX); // 최단 거리를 저장할 배열

    dist[s] = 0; // 시작 정점의 최단 거리는 0으로 초기화

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (u == e) break; // 목표 정점에 도달하면 종료

        // 현재 정점에서 갈 수 있는 모든 정점을 확인
        for (int v : graph[u]) {
            if (v != k && dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[e];
}

int main() {
    int n, m, s, e; // 정점 수, 간선 수, 시작 정점, 목표 정점
    cin >> n >> m >> s >> e;

    vector<vector<int>> graph(n+1); //수정

    // 간선 정보 입력
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1); // 무방향 그래프인 경우
    }

    for (int i = 1; i <= n; ++i) {
        if (i != s) {
            int shortestDistance = dijkstra(s - 1, e - 1, i - 1, graph);

            // 최단 경로 출력
            if (shortestDistance != INT_MAX) {
                cout << shortestDistance + 1;
            } else {
                cout << -1; // 이동이 불가능한 경우
            }
        }
        else {
          cout << -1;
        }
        cout << '\n';
    }
    return 0;
}
