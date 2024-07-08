#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<deque>
#include<map>
#include<set>

#define int long long
#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int inf=2100000000;

class segment_tree {
public:
    int SZ;
    vector<ll> T;
    segment_tree(int n){
        SZ=n;
        T.assign(SZ*2, 0);
    }
    segment_tree(vector<int> x){
        SZ=x.size();
        T.resize(SZ*2);
        for(int i=0; i<SZ; i++) T[i+SZ]=x[i];
        for(int i=SZ-1; i>0; i--) T[i]=T[i*2]+T[i*2+1];
    }
    void insert(int x, ll v){ // x번째 수를 v로 지정, x는 0 이상 SZ 미만
        T[x+=SZ]=v;
        while(x/=2) T[x]=T[x*2]+T[x*2+1];
    }
    ll sum(int l, int r){ // [l, r] 구간의 합
        ll ans=0;
        for(l+=SZ, r+=SZ; l<=r; l/=2, r/=2){
            if(l%2==1) ans+=T[l++];
            if(r%2==0) ans+=T[r--];
        }
        return ans;
    }
};

signed main() {
    freopen("input.txt", "r", stdin);
    ioset();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        vector<int> sorted_a = a, sorted_b = b;
        sort(sorted_a.begin(), sorted_a.end());
        sort(sorted_b.begin(), sorted_b.end());

        if (sorted_a == sorted_b) {
            vector<pair<int, int>> A(n), B(n);
            for (int i = 0; i < n; ++i) A[i] = {a[i], i};
            for (int i = 0; i < n; ++i) B[i] = {b[i], i};

            sort(A.begin(), A.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
                return (x.first != y.first) ? (x.first > y.first) : (x.second > y.second);
            });

            sort(B.begin(), B.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
                return (x.first != y.first) ? (x.first > y.first) : (x.second > y.second);
            });

            segment_tree ta(n), tb(n);
            int ansA = 0, ansB = 0;

            for (auto [value, idx] : A) {
                ansA += ta.sum(0, idx);
                ta.insert(idx, 1);
            }

            for (auto [value, idx] : B) {
                ansB += tb.sum(0, idx);
                tb.insert(idx, 1);
            }
            cout<<ansA%2<<' '<<ansB%2<<endl;
            cout << (ansA % 2 == ansB % 2 ? "YES" : "NO") << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
