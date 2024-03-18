#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> info(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> info[i][0] >> info[i][1] >> info[i][2];
    }

    sort(info.begin(), info.end());

    vector<int> dp(n);
    vector<int> s(n), e(n), c(n), nxt(n);

    for (int i = 0; i < n; i++) {
        s[i] = info[i][0];
        e[i] = info[i][1];
        c[i] = info[i][2];
    }

    for (int i = 0; i < n; i++) {
        nxt[i] = upper_bound(s.begin(), s.end(), e[i]) - s.begin();
    }

    for (int idx = n - 1; idx >= 0; idx--) {
        dp[idx] = max(dp[idx + 1], dp[nxt[idx]] + c[idx]);
    }

    cout << dp[0] << endl;

    return 0;
}
