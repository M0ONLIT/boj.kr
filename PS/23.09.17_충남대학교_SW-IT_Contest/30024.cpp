#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cassert>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> mem(n, vector<int>(m, 0));
    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    auto nearby = [&](int r, int c) -> vector<pair<int, int>> {
        vector<pair<int, int>> adjacent_cells;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (const auto& dir : directions) {
            int dr = dir.first;
            int dc = dir.second;
            int nr = r + dr;
            int nc = c + dc;

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !mem[nr][nc]) {
                adjacent_cells.push_back({nr, nc});
            }
        }

        return adjacent_cells;
    };

    priority_queue<tuple<int, int, int>> Q;

    for (int i = 0; i < m; i++) {
        Q.push(make_tuple(a[0][i], 0, i));
        mem[0][i] = 1;
        Q.push(make_tuple(a[n - 1][i], n - 1, i));
        mem[n - 1][i] = 1;
    }

    for (int i = 1; i < n - 1; i++) {
        Q.push(make_tuple(a[i][0], i, 0));
        mem[i][0] = 1;
        Q.push(make_tuple(a[i][m - 1], i, m - 1));
        mem[i][m - 1] = 1;
    }

    int tc;
    cin >> tc;

    while (tc--) {
        int r, c;
        while(1){
            auto [s, R, C] = Q.top();
            Q.pop();
            if(mem[R][C]!=1) continue;
            r=R, c=C;
            break;
        }

        cout << r + 1 << " " << c + 1 << "\n";
        mem[r][c]++;

        vector<pair<int, int>> neighbors = nearby(r, c);
        for (const auto& neighbor : neighbors) {
            int i = neighbor.first;
            int j = neighbor.second;
            Q.push(make_tuple(a[i][j], i, j));
            mem[i][j] = 1;
        }
    }

    return 0;
}
