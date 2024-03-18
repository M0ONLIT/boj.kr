#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
vector<pll> points;
set<pll> convex_hull;

ll ccw(pll p1, pll p2, pll p3){
    return (p3.second-p1.second)*(p2.first-p1.first)+(p1.second-p2.second)*(p3.first-p1.first);
}

bool compare_acc(const pll &x, const pll &y) const{
    return x.first*y.second<y.first*x.second;
}

int main(){
    ioset();
    int i, j;
    cin>>n;
    points.assign(n, {0, 0});
    for(i=0; i<n; i++) cin>>points[i].first>>points[i].second;

    sort(points.begin(), points.end(), compare_acc);
    for(auto i: points())
}
