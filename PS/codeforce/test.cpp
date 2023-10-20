#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> D;

    for (int i = 2; i < k + 2; i++) {
        std::cout << "1 " << i << "\n";
        D.push_back(i);
    }

    int cnt = 0, curr;
    for (int i = k + 2; i <= n; i++) {
        if (cnt % (k - 1) == 0) {
            curr = D[0];
            D.erase(D.begin());
        }
        std::cout << curr << " " << i << "\n";
        D.push_back(i);
        cnt++;
    }

    return 0;
}
