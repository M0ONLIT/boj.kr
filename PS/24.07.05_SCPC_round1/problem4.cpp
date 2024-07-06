#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<deque>
#include<cmath>
#define ioset() ios_base::sync_with_stdio(0), cin.tie(0)
using namespace std;
typedef long long ll;

template<typename T>
void print_vector(vector<T> &v){
    for(T i: v) cout<<i<<' ';
    cout<<'\n';
}

void print_state(vector<int> &A, vector<int> &B, vector<int> &left, vector<int> &right){
    cout<<"current state is..\n";
    cout<<"A: "; print_vector(A);
    cout<<"B: "; print_vector(B);
    cout<<"left: "; print_vector(left);
    cout<<"right: "; print_vector(right);
}

int solve(){
    int n, l; cin>>n>>l;
    int i, sai;
    vector<int> A(n), B(n), left(n), right(n);
    for(i=0; i<n; i++) cin>>A[i];
    for(i=0; i<n; i++) cin>>B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for(i=0; i<n; i++)
        if(!(A[i]-l<=B[i] && B[i]<=A[i]+l))
            return -1;

    int ptr_s=0, ptr_e=0;
    for(i=0; i<n; i++){
        while(A[ptr_s]<B[i]-l) ptr_s++;
        while(A[ptr_e]<=B[i]+l && ptr_e<n) ptr_e++;
        ptr_e--;
        left[i]=ptr_s; right[i]=ptr_e;
    }
    //print_state(A, B, left, right); //debug

    int ans=0;
    sai=-1;
    for(i=0; i<n; i++){
        ans=max(ans, B[i]-A[max(sai+1, left[i])]);
        sai=right[i]==i?i:sai;
    }
    sai=n;
    for(i=n-1; i>=0; i--){
        ans=max(ans, A[min(sai-1, right[i])]-B[i]);
        sai=left[i]==i?i:sai;
    }
    return ans;
}

int main(int argc, char** argv){
    ioset();
	int T; cin>>T;
	for(int tc=1; tc<=T; tc++) {
		cout<<"Case #"<<tc<<endl;
		cout<<solve()<<endl;
	}
	return 0;
}
