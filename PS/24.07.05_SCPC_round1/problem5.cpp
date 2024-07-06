#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<tuple>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
typedef tuple<int, int, int> iii;

const int mx=50000;
int state;
unordered_map<ll, int> m;

void Add(ll x){
    m[x]++;
    if(x>=2){
        while(m[x]>=x && x<=mx){
            state++;
            m[x]-=x;
            m[x*x]++;
            x*=x;
        }
    }
}

void Minus(ll x){
    if(x>=2){
        while(m[x]==0){
            state--;
            m[x]=x-1;
            x*=x;
        }
    }
    m[x]--;
}

void print_state(int l, int r){
    cout<<"current state is..."<<endl;
    cout<<"query is.. "<<l<<' '<<r<<endl;
    for(auto p: m){
        cout<<p.first<<' '<<p.second<<endl;
    }
}

int main(int argc, char** argv){

    freopen("./input.txt", "r", stdin); //file input

    ioset();
	int T; cin>>T;
	for(int tc=1; tc<=T; tc++) {
        int n, q;
        cin>>n;
        vector<ll> v(n), ans(n);
        for(int i=0; i<n; i++) cin>>v[i];
        cin>>q;
        vector<iii> query(q);
        for(int i=0; i<q; i++){
            int l, r; cin>>l>>r;
            query[i]=make_tuple(l-1, r-1, i);
        }

        int SQRT=sqrt(n);
        sort(query.begin(), query.end(), [&SQRT](iii &x, iii &y)->bool{
            if(get<0>(x)/SQRT==get<0>(y)/SQRT)
                return get<1>(x)<get<1>(y);
            return get<0>(x)/SQRT<get<0>(y)/SQRT;
        });

        int s=-1, e=-1;
        state=0; m.clear();
        for(iii &x: query){
            int l, r, idx; tie(l, r, idx)=x;
            if(s==-1){
                s=l; e=r;
                for(int i=s; i<=e; i++) Add(v[i]);
            }
            else{
                while(e<r) Add(v[++e]);
                while(e>r) Minus(v[e--]);
                while(s<l) Minus(v[s++]);
                while(s>l) Add(v[--s]);
            }
            ans[idx]=state;
            //print_state(l, r);
        }
        cout<<"Case #"<<tc<<'\n';
        for(int i=0; i<q; i++) cout<<ans[i]<<' ';
	}

	return 0;
}
