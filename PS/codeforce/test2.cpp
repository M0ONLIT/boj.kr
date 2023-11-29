#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class SegmentTree {
public:
    vector<int> v;
    vector<int> info;
    int m;

    int make_tree(int start, int end, int i) {
        if (start == end) {
            v[i] = info[start];
        } else {
            int mid = (start + end) / 2;
            int left = make_tree(start, mid, i * 2);
            int right = make_tree(mid + 1, end, i * 2 + 1);
            v[i] = left + right;
        }
        return v[i];
    }

    int _sum(int x, int y, int start, int end, int i) {
        if (y < start || x > end) {
            return 0;
        }
        if (x <= start && end <= y) {
            return v[i];
        }
        int mid = (start + end) / 2;
        int left = _sum(x, y, start, mid, i * 2);
        int right = _sum(x, y, mid + 1, end, i * 2 + 1);
        return left + right;
    }

    void _insert(int index, int value, int start, int end, int i) {
        if (index < start || index > end) {
            return;
        }
        if (start == end && index == start) {
            info[index] = value;
            v[i] = value;
            return;
        }
        int mid = (start + end) / 2;
        _insert(index, value, start, mid, i * 2);
        _insert(index, value, mid + 1, end, i * 2 + 1);
        v[i] = v[i * 2] + v[i * 2 + 1];
    }

    SegmentTree(vector<int>& x) {
        m = x.size();
        v.assign(m * 4, 0);
        info = x;
        make_tree(0, m - 1, 1);
    }

    int sum(int x, int y) {
        return _sum(x, y, 0, m - 1, 1);
    }

    void insert(int index, int value) {
        _insert(index, value, 0, m - 1, 1);
    }

    void init(int x = 0) {
        v.assign(m * 4, x);
    }
};

vector<int> coordinate_compression(vector<int>& lst) {
    vector<int> sorted_list = lst;
    sort(sorted_list.begin(), sorted_list.end());
    sorted_list.erase(unique(sorted_list.begin(), sorted_list.end()), sorted_list.end());
    map<int, int> compression_dict;
    for (int i = 0; i < sorted_list.size(); ++i) {
        compression_dict[sorted_list[i]] = i + 1;
    }
    vector<int> compressed;
    for (int value : lst) {
        compressed.push_back(compression_dict[value]);
    }
    return compressed;
}

int main() {
    int n;
    cin >> n;

    vector<int> arrx(n), arry(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        arrx[i] = y / x;
        arry[i] = x;
    }

    int m;
    cin >> m;

    vector<int> qx(m), qy(m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        qx[i] = y / x;
        qy[i] = x;
    }

    vector<int> lx = coordinate_compression(arrx);
    vector<int> qx_new = coordinate_compression(qx);
    arrx = vector<int>(lx.begin(), lx.begin() + n);
    qx = vector<int>(lx.begin() + n, lx.end());
    vector<int> ly = coordinate_compression(arry);
    vector<int> qy_new = coordinate_compression(qy);
    arry = vector<int>(ly.begin(), ly.begin() + n);
    qy = vector<int>(ly.begin() + n, ly.end());

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        points[i] = make_pair(arrx[i], arry[i]);
    }
    sort(points.begin(), points.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    vector<tuple<int, int, int>> query(m);
    for (int i = 0; i < m; ++i) {
        query[i] = make_tuple(qx[i], qy[i], i);
    }
    sort(query.begin(), query.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        return get<1>(a) < get<1>(b);
    });

    vector<int> ans(m, 0);
    int ptr = 0;
    SegmentTree tree(vector<int>(200005, 0));

    for (auto& q : query) {
        int x = get<0>(q);
        int y = get<1>(q);
        int idx = get<2>(q);

        while (ptr < n && points[ptr].second <= y) {
            tree.insert(points[ptr].first, 1);
            ptr++;
        }
        ans[idx] = tree.sum(0, x);
    }

    for (int a : ans) {
        cout << a << endl;
    }

    return 0;
}
