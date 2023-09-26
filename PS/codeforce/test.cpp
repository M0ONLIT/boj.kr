#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    for(int i=1; i<=N; i++){
        if(i % 2 == 1) cout << "#" + string(N-1, '.') << "\n";
        else cout << string(N-2+N%2, '.') + "#" + (N % 2 ? "" : ".") << "\n";
    }
}
