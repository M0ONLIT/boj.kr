#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>

using namespace std;

int truth[55];
int check_peo[55], check_par[55];
vector<int> people[55], party[55];

void ww(int x){ //x는 사람
  if(check_peo[x])
    return;
  check_peo[x]=1;
  for(int i: people[x]){
    if(check_par[i])
      continue;
    check_par[i]=1;
    for(int j: party[i]){
      ww(j);
    }
  }
}

int n, m, o;
int main(){
  ios_base::sync_with_stdio(NULL);
  cin.tie(0); cout.tie(0);

  int i,j,k,x;
  cin>>n>>m>>o;
  for(i=0; i<o; i++){
    cin>>x;
    truth[x]=1;
  }

  for(i=0; i<m; i++){
    cin>>x;
    for(j=0; j<x; j++){
      cin>>k;
      people[k].push_back(i); //k번 사람이 참여한 파티(i)
      party[i].push_back(k); //i번 파티에 참여한 사람(k)
    }
  }

  for(i=1; i<=n; i++){
    if(truth[i]){
      ww(i);
    }
  }

  int count=0;
  for(i=0; i<m; i++){
    count+=!check_par[i];
  }
  cout<<count;
}
