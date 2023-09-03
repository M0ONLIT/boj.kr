#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

class segment_tree{
public:
  vector<ll> info;
  vector<ll> v;
  vector<ll> v2;
  ll m;

  segment_tree(vector<ll> &x){
    m=x.size();
    v=vector<ll>(m*4);
    v2=vector<ll>(m*4);
  }

  void sum(ll x, ll y, ll value, ll value2){
    sum(x, y, value, value2, 0, m-1, 1);
  }
  void sum(ll x, ll y, ll value, ll value2, ll start, ll end, ll i){
    ll mid=(start+end)/2;
    if(y<start || end<x)
      return;
    else if(x<=start && end<=y){
      if(!v[i]){
        v[i]=value;
        v2[i]=value2;
      }
    }
    else{
      sum(x, y, value, value2, start, mid, i*2);
      sum(x, y, value, value2, mid+1, end, i*2+1);
    }
  }

  pii insert(ll index){
    return insert(index, 0, 0, m-1, 1);
  }
  pii insert(ll index, ll value, ll start, ll end, ll i){ //{순서, 색}
    ll mid=(start+end)/2;
    if(index<start || end<index)
      return make_pair(0, 0);
    else if(start==end && mid==index){
      return make_pair(v2[i], v[i]);
    }
    else if(v[i]){
      pii p=make_pair(v2[i], v[i]);
      pii q=insert(index, value, start, mid, i*2);
      pii r=insert(index, value, mid+1, end, i*2+1);
      if(q.second==0 && r.second==0)
        return p;
      else if(q.second==0){
        return (p.first<r.first)?p:r;
      }
      else if(r.second==0){
        return (p.first<q.first)?p:q;
      }
      else{
        cout<<'!';
        return make_pair(0, 0);
      }
    }
    else{
      pii p=insert(index, value, start, mid, i*2);
      pii q=insert(index, value, mid+1, end, i*2+1);
      return (p.second==0)?q:p;
    }
  }
};

ll n, q;

int main(){
  ioset();
  ll i, a, b, x;
  cin>>n>>q;
  vector<ll> v(n+5);
  segment_tree tree(v);
  for(i=1; i<=q; i++){
    cin>>a>>b>>x;
    tree.sum(a, b, x, i);
  }
  for(i=1; i<=n; i++){
    cout<<tree.insert(i).second<<' ';
  }
}
