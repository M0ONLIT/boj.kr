#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<deque>
#include<map>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long

using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> iii;

// 선택한 칸들이 상하좌우로 인접하지 않는지 확인하는 함수
bool isValid(const vector<pair<int, int>>& selection, int r, int c) {
    for (const auto& i : selection) {
        int sr, sc;
        tie(sr, sc)=i;
        if (abs(sr - r) + abs(sc - c) == 1) {
            return false;
        }
    }
    return true;
}

// 백트래킹을 이용해 최대 가중치 합을 계산하는 함수
int backtrack(const vector<pair<int, int>>& choices, vector<pair<int, int>>& selection, int index, int k, const vector<vector<int>>& weights) {
    if (selection.size() == k) {
        int sum = 0;
        for (const auto& i : selection) {
            int r, c; tie(r, c)=i;
            sum += weights[r][c];
        }
        return sum;
    }

    if (index >= choices.size()) {
        return 0;
    }

    int maxWeight = 0;
    int r = choices[index].first;
    int c = choices[index].second;

    // 현재 위치를 선택하는 경우
    if (isValid(selection, r, c)) {
        selection.push_back({r, c});
        for (const auto& i : selection) {
            int r, c; tie(r, c)=i;
            maxWeight += weights[r][c];
        }
        maxWeight = max(maxWeight, backtrack(choices, selection, index + 1, k, weights));
        selection.pop_back();
    }

    // 현재 위치를 선택하지 않는 경우
    maxWeight = max(maxWeight, backtrack(choices, selection, index + 1, k, weights));

    return maxWeight;
}

int solve(int n, int m, int k, const vector<vector<int>>& weights) {
    vector<tuple<int, int, int>> cells;

    // 가중치와 좌표를 함께 저장
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cells.emplace_back(weights[i][j], i, j);
        }
    }

    // 가중치가 큰 순서대로 정렬
    sort(cells.rbegin(), cells.rend());

    // 상위 50개의 좌표를 사용
    vector<pair<int, int>> topCells;
    for (int i = 0; i < min(50LL, (int)cells.size()); ++i) {
        int r = get<1>(cells[i]);
        int c = get<2>(cells[i]);
        topCells.emplace_back(r, c);
    }

    // 백트래킹으로 k개의 칸을 선택해 최대 가중치 합을 찾기
    vector<pair<int, int>> selection;
    return backtrack(topCells, selection, 0, k, weights);
}

signed main() {
    ioset();
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> weights(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> weights[i][j];
        }
    }

    int result = solve(n, m, k, weights);
    cout << result;

    return 0;
}
