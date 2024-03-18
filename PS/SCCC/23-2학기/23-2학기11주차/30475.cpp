#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#include <algorithm>
#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;
using namespace std;

class SegmentTree {
public:
    vector<ll> v;
    vector<ll> info;
    int m;

    ll _find(int x, int y, int start, int end, int i) {
        if (y < start || x > end) {
            return -1;
        }
        if (x <= start && end <= y) {
            return v[i];
        }
        int mid = (start + end) / 2;
        int left = _find(x, y, start, mid, i * 2);
        int right = _find(x, y, mid + 1, end, i * 2 + 1);
        if (left == -1) {
            return right;
        } else if (right == -1) {
            return left;
        } else {
            return info[left] <= info[right] ? left : right;
        }
    }

    SegmentTree(vector<ll>& x) {
        m = x.size();
        v = vector<ll>(m * 4, 0);
        info = x;
        //make_tree(0, m - 1, 1);
    }

    ll find(int x, int y) {
        return _find(x, y, 0, m - 1, 1);
    }

    ll get(int x, int y) {
        ll min_index = find(x, y);
        return info[min_index];
    }

    void insert(int index, ll value) {
        _insert(index, value, 0, m - 1, 1);
    }

    void _insert(int index, ll value, int start, int end, int i) {
        if (index < start || index > end) {
            return;
        }
        if (start == end && index == start) {
            info[index] = value;
            v[i] = index;
            return;
        }
        int mid = (start + end) / 2;
        _insert(index, value, start, mid, i * 2);
        _insert(index, value, mid + 1, end, i * 2 + 1);
        if (info[v[i * 2]] <= info[v[i * 2 + 1]]) {
            v[i] = v[i * 2];
        } else {
            v[i] = v[i * 2 + 1];
        }
    }
};

struct Point {
    ll x, y;
};

ll ccw(Point p1, Point p2, Point p3) {
    return (p3.y - p1.y) * (p2.x - p1.x) + (p1.y - p2.y) * (p3.x - p1.x);
}

int main() {
    ioset();
    ll inf=1e18;

    int test_cases;
    cin >> test_cases;

    for (int tc = 0; tc < test_cases; ++tc) {
        vector<tuple<int, int, int, int>> arr;
        arr.emplace_back(0, 0, 0, 0);
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            int x, y, a, b;
            cin >> x >> y >> a >> b;
            arr.emplace_back(x, y, a, b);
        }
        vector<ll> temp(n+1, inf);
        SegmentTree tree2(temp); temp[0]=0;
        SegmentTree tree1(temp);
        vector<pair<int, Point>> stack_upper, stack_lower;
        stack_upper.emplace_back(0, Point{0, 0});
        stack_lower.emplace_back(0, Point{0, 0});
        vector<int> state(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            auto [x, y, a, b] = arr[i];
            Point value; value.x=x, value.y=y;
            while (stack_upper.size() >= 2 && ccw(stack_upper[stack_upper.size() - 2].second, stack_upper[stack_upper.size() - 1].second, value) > 0) {
                auto [p, acc] = stack_upper.back();
                stack_upper.pop_back();
                if ((state[p] & 2) == 0) {
                    tree2.insert(p, tree1.get(p, p));
                    tree1.insert(p, inf);
                }
                state[p] = 0;
            }
            state[i] |= 1;
            stack_upper.emplace_back(i, value);

            while (stack_lower.size() >= 2 && ccw(stack_lower[stack_lower.size() - 2].second, stack_lower[stack_lower.size() - 1].second, value) < 0) {
                auto [p, acc] = stack_lower.back();
                stack_lower.pop_back();
                if ((state[p] & 1) == 0) {
                    tree2.insert(p, tree1.get(p, p));
                    tree1.insert(p, inf);
                }
                state[p] = 0;
            }
            state[i] |= 2;
            stack_lower.emplace_back(i, value);

            ll ans = min(tree1.get(max(0, i - m), i - 1) + a, tree2.get(max(0, i - m), i - 1) + b);
            tree1.insert(i, ans);
        }
        cout << tree1.info[n] << '\n';
    }
    return 0;
}
