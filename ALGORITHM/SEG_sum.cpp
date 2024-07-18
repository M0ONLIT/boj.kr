#include<vector>
#include<iostream>
using namespace std;
typedef long long U;

template<typename U>
class segment_tree {
public:
    int SZ;
    vector<U> T;

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

    void insert(int x, U v){ // x번째 수를 v로 지정, x는 0 이상 SZ 미만
        T[x+=SZ]=v;
        while(x/=2) T[x]=T[x*2]+T[x*2+1];
    }

    U sum(int x, int y) { // 구간 합을 구한다.
        return sum(x, y, 0, m - 1, 1);
    }
    U sum(int x, int y, int start, int end, U i) {
        U mid = (start + end) / 2;
        if (y < start || end < x)
            return 0;
        else if (x <= start && end <= y)
            return v[i];
        else
            return sum(x, y, start, mid, i * 2) + sum(x, y, mid + 1, end, i * 2 + 1);
     }

    void init(){
        T.assign(SZ*2, 0);
    }
};


int main(){
    cout<<1;
    return 0;
}
