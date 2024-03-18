#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

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
            info[index] += value;
            v[i] += value;
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

int gcd(int x, int y){
    if(y==0) return x;
    return gcd(y, x%y);
}

pii frac(pii x){
    int _gcd=gcd(x.first, x.second);
    return {x.first/_gcd, x.second/_gcd};
}

int compare_fraction(const pii& a, const pii& b){
    return (ll)a.first*b.second < (ll)a.second*b.first;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    vector<pii> arrx(n);
    vector<int> new_arrx(n), arry(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        arrx[i] = frac({y, x});
        arry[i] = x;
    }

    int m;
    cin >> m;

    vector<pii> qx(m);
    vector<int> new_qx(m), qy(m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        qx[i] = frac({y, x});
        qy[i] = x;
    }
    set<pii, decltype(compare_fraction)*> compression_set(compare_fraction);
    map<pii, int> compression_dict;
    int start = 1;
    for(auto i : arrx) compression_set.insert(i);
    for(auto i : qx) compression_set.insert(i);
    for(auto iter = compression_set.begin(); iter != compression_set.end(); iter++){
        compression_dict[*(iter)]=start++;
    }
    for (int i = 0; i < n; ++i) new_arrx[i] = compression_dict[arrx[i]];
    for (int i = 0; i < m; ++i) new_qx[i] = compression_dict[qx[i]];

    vector<pii> points(n);
    for (int i = 0; i < n; ++i) {
        points[i] = make_pair(new_arrx[i], arry[i]);
    }
    sort(points.begin(), points.end(), [](const pii& a, const pii& b) {
        return a.second < b.second;
    });

    vector<tuple<int, int, int>> query(m);
    for (int i = 0; i < m; ++i) {
        query[i] = make_tuple(new_qx[i], qy[i], i);
    }
    sort(query.begin(), query.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        return get<1>(a) < get<1>(b);
    });

    vector<int> ans(m);
    int ptr = 0;
    vector<int> v(200005);
    SegmentTree tree(v);

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

    for (int a : ans)
        cout << a << endl;

    return 0;
}
