#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

class SegmentTree {
private:
    int m;
    vector<int> v;
    vector<int> info;

    int make_tree(int start, int end, int i) {
        if (start == end) {
            v[i] = start;
        } else {
            int mid = (start + end) / 2;
            int left = make_tree(start, mid, i * 2);
            int right = make_tree(mid + 1, end, i * 2 + 1);
            if (info[left] >= info[right]) { // maximum
                v[i] = left;
            } else {
                v[i] = right;
            }
        }
        return v[i];
    }

    int _find(int x, int y, int start, int end, int i) {
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
            return info[left] >= info[right] ? left : right; // maximum
        }
    }

    void _insert(int index, int value, int start, int end, int i) {
        if (index < start || index > end) {
            return;
        }
        if (start == end && start == index) {
            info[index] = value;
            v[i] = index;
            return;
        }
        int mid = (start + end) / 2;
        _insert(index, value, start, mid, i * 2);
        _insert(index, value, mid + 1, end, i * 2 + 1);
        if (info[v[i * 2]] >= info[v[i * 2 + 1]]) { // maximum
            v[i] = v[i * 2];
        } else {
            v[i] = v[i * 2 + 1];
        }
    }

public:
    SegmentTree(vector<int>& x) {
        m = x.size();
        v.assign(m * 4, 0);
        info = x;
        make_tree(0, m - 1, 1);
    }

    int find(int x, int y) {
        return _find(x, y, 0, m - 1, 1);
    }

    int get(int x, int y) {
        int min_index = find(x, y);
        return info[min_index];
    }

    void insert(int index, int value) {
        _insert(index, value, 0, m - 1, 1);
    }

    void init(int x) {
        fill(v.begin(), v.end(), x);
    }
};

int main() {
    ioset();

    int n;
    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    vector<pair<int, int>> arr;
    for (int i = 0; i < n; ++i) {
        arr.emplace_back(array[i], -i);
    }
    sort(arr.begin(), arr.end());

    vector<int> v(n+10);
    SegmentTree seg(v);
    vector<int> back(n, -1);

    for (auto& p : arr) {
        int idx = -p.second;
        int val = p.first;
        int i = seg.find(0, max(idx - 1, 0));
        if (seg.get(i, i) != 0) {
            back[idx] = i;
        }
        seg.insert(idx, seg.get(i, i) + 1);
    }

    int ans = seg.find(0, n - 1);
    vector<int> ans_list;
    while (ans != -1) {
        ans_list.push_back(array[ans]);
        ans = back[ans];
    }

    reverse(ans_list.begin(), ans_list.end());
    cout << ans_list.size() << '\n';
    for (int x : ans_list)
        cout << x << ' ';
}
