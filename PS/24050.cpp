#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int mx=210000;

int nanugi=2;
int mod[mx+5];

ll ncr(int n, int k){
    return mod[n]-mod[n-k]-mod[k]==0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll i, j;
	for(i=2; i<=mx; i*=2)
        for(j=1; i*j<=mx; j++)
            mod[i*j]++;
    for(i=1; i<=mx; i++)
        mod[i]+=mod[i-1];


    int n, m, x, ans=0;
    cin>>n>>m;
	for(i=0; i<n; i++){
        cin>>x;
        ans+=x*(ncr(n+m-2-i, n-1-i));
	}
    for(i=0; i<m; i++){
        cin>>x;
        ans+=x*(ncr(n+m-2-i, m-1-i));
    }
	cout<<(ans%2);
}
