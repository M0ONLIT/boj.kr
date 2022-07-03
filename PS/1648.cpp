#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int dp[17000][15], visit[17000][15];
vector<int> state[17000];
int n, m;

void w(int now, int bit, int index){
    //cout<<now<<' '<<bit<<' '<<index<<endl;
    if(index==n){
        state[now].push_back(bit);
        return;
    }
    if(now & (1<<index))
        w(now, bit, index+1);
    if((!(now & (3<<index))) && (index<n-1))
        w(now, bit, index+2);
    if(!(now & (1<<index)))
        w(now, bit|(1<<index), index+1);
}

int p(int now, int index){
    int ans=0;
    if(index==0)
        return now==0;
    if(visit[now][index])
        return dp[now][index];
    visit[now][index]=1;
    for(int i: state[now]){
        ans+=p(i, index-1);
        ans%=9901;
    }
    return dp[now][index]=ans;  
}

int main(){
    cin>>n>>m;
    if(n>m)
        swap(n, m);
    
    for(int i=0; i<(1<<n); i++)
         w(i, 0, 0);
    cout<<p(0, m);
}
