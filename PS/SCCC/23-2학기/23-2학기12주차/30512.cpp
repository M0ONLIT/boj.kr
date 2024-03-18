#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<set>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> iii;
const int inf=1e9+7;
const int mx=100005;

int n, q, arr[mx], ans[mx], nu[mx];
set<pii> s;
vector<iii> add, rm;

int main(){
  ioset();
  int i, x, y, z;
  cin>>n;
  for(i=1; i<=n; i++){
    cin>>arr[i];
    ans[i]=arr[i];
  }
  cin>>q;
  for(i=1; i<=q; i++){
    cin>>x>>y>>z;
    add.emplace_back(x, z, i); //-면 넣고 +면 빼기
    rm.emplace_back(y, z, i);
  }
  sort(add.begin(), add.end());
  sort(rm.begin(), rm.end());
  int ptr1=0, ptr2=0;
  for(i=1; i<=n; i++){
    int idx, value, q_th;
    for(iii temp={i, inf, inf}; add[ptr1]<temp && ptr1<q; ptr1++){
      tie(idx, value, q_th)=add[ptr1];
      s.insert({value, q_th});
    }

    if(!s.empty()){
      tie(value, q_th)=*s.begin();
      if(value<ans[i])
        ans[i]=value;
      else
        q_th=0;
    }
    else q_th=0;
    nu[q_th]++;

    for(iii temp={i, inf, inf}; rm[ptr2]<temp && ptr2<q; ptr2++){
      tie(idx, value, q_th)=rm[ptr2];
      s.erase({value, q_th});
    }
  }
  for(i=1; i<=n; i++){
    cout<<ans[i]<<' ';
  }
  cout<<'\n';
  for(i=1; i<=q; i++){
    nu[i]+=nu[i-1];
    cout<<nu[i]<<' ';
  }
}
