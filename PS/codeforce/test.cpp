#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> input_vector(int n){
  vector<int> v(n);
  for(int i=0; i<n; i++)
    cin>>v[i];
  return v;
}

int n;
int main(){
  ioset();
  int w, x, y, z, q;
  string s;
  cin>>n;
  vector<int> v=input_vector(n);
  cin>>s>>q;
  while(q--){
    cin>>w>>x>>y;
    if(w==1){
      cin>>z;
    }
    else if(w==2){

    }
    else{ //w==3

    }
  }
}
