#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mx=1000001;
int score[mx], check[mx];
int arr[100005], n;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int i, j, x;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>x;
        check[x]=1;
        arr[i]=x;
    }
    for(i=0; i<n; i++){
        for(j=2; j*arr[i]<mx; j++){
            if(check[j*arr[i]]){
                score[arr[i]]++;
                score[j*arr[i]]--;
            }
        }
    }
    for(i=0; i<n; i++)
        cout<<score[arr[i]]<<' ';
}
