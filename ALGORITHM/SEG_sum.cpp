#include <vector>
#include<iostream>
using namespace std;
typedef long long ll;

class segment_tree {
public:
    int SZ;
    vector<ll> T;

    segment_tree(int n){
        SZ=n;
        T.resize(SZ*2);
    }
    segment_tree(vector<int> &x){
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

    void init(){
        T.assign(SZ*2, 0);
    }
};


int main(){
    cout<<1;
    return 0;
}
