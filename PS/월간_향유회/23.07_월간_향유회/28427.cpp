#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

//const ll inf=(1LL<<63)-1;

const int MAX=5000000;
int q;
int sosu[MAX+5]={1, };
int arr[MAX/10+10];
int nu[MAX/10+10];
ll t;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin>>q;

  int i, j, k;
  for(i=2; i<=MAX; i++){
    if(sosu[i]==0){
      for(j=2; j*i<=MAX; j++){
        sosu[j*i]=1;
      }
    }
  } //sosu[i]=0; 이면 소수
  for(i=2; i<MAX/10+10; i++){
    if(sosu[2*i+1]==0){
      arr[i]++;
    }
    nu[i]=arr[i]+nu[i-1];
  }
  for(i=0; i<q; i++){
    int l, r;
    cin>>l>>r;
    cout<<nu[r-1]-nu[l-1]<<'\n';
  }
}
