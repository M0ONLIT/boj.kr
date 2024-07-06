#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<deque>
#include<map>
#include<set>
#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++) {
        int n;
        long long ans=0;
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        sort(v.begin(), v.end());
        for(int i=0; i<n/4; i++){
            ans+=2*(v[n-i-1]-v[i]);
        }
		cout << "Case #" << test_case+1 << endl;
		cout << ans << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
