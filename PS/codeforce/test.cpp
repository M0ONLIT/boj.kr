#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, ans;
vector<int> arr, stack;
vector<pii> info;

int main(){
    ioset();
	int i;
	cin>>n;
	info.resize(n, {-1, -1});
	for(i=0; i<n; i++){
		cin>>j;
		arr.push_back(j);
	}
	for(idx=0; idx<n; idx++){
		while(!stack.empty() && stack.back()<arr[idx])
	}
	cout<<ans;
}
