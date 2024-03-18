#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<stdlib.h>
#include<time.h>

using namespace std;
typedef long long ll;
const ll nanugi=1e9+7;
const int MX=1000000;

int fib[105], fib_r[105];
map<int, vector<int>> M;
int n;

int randint(int a, int b){ //2~99
  return rand()%(b-a+1)+a;
}

vector<int> randvector(){
  int cnt=0, s=0, x;
  vector<int> v;
  while(cnt+s-1<100){
    x=randint(1, min(99, 105-cnt-s+1));
    v.push_back(x);
    s+=x;
    cnt++;
  }
  v.pop_back();
  return v;
}

int calvec(vector<int> &v, int option){//1은 리버스
  ll ans=(option?n:1);
  for(auto i: v){
    if(!option) ans*=fib[i];
    else ans*=fib_r[i];
    ans%=nanugi;
  }
  return ans;
}

ll POW(ll a, ll r){
  if(r==0)
    return 1;
  ll k=POW(a, r/2);
  return (k*k)%nanugi*(r%2?a:1)%nanugi;
}

int main(){
  srand(time(0));
  cin>>n;

  if(n==0){
    cout<<".##\n##.";
    return 0;
  }


  ll i=1, j=1;
  for(int x=0; x<100; x++){
    fib[x]=i;
    fib_r[x]=POW(i, nanugi-2);
    ll temp=(i+j)%nanugi;
    i=j, j=temp;
  } //전처리

  for(int x=0; x<=MX; x++){
    vector<int> rvec=randvector();
    int rval=calvec(rvec, 0);

    M[rval]=rvec;
  }
  vector<int> ans1, ans2;
  while(1){
    vector<int> rvec=randvector();
    int rval=calvec(rvec, 1);
    if(M.find(rval)!=M.end()){
      ans1=rvec, ans2=M[rval];
      break;
    }
  }

  for(int o=0; o<2; o++){
    for(int i: ans1){
      for(int j=0; j<i; j++) cout<<'.';
      cout<<'#';
    }
    for(int i: ans2){
      for(int j=0; j<i; j++) cout<<'.';
      cout<<'#';
    }
    cout<<'\n';
  }
}
