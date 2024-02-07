#include<map>
#include<iostream>
using namespace std;

map<string, int> M;
int main(){
    int n, mx=-1;
    string s, answer;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>s;
        M[s]++;
        if(M[s]>mx || (M[s]==mx && s<answer)){
            mx=M[s];
            answer=s;
        }
    }
    cout<<answer;
}
