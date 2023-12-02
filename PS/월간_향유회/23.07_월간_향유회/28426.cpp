#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<cstdlib>
#include<ctime>

using namespace std;
typedef long long ll;

int randint(int x, int y){
  return rand()%(y-x+1)+x;
}

ll sum;
int n, i, counter;
int arr[100005];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  srand(time(0));

  cin>>n;
  arr[0]=3;

  while(counter!=1){
    counter=0;
    sum=arr[0];
    for(i=1; i<n; i++){
      arr[i]=arr[i-1]+randint(3, 4);
      sum+=arr[i];
    }
    for(i=0; i<n; i++){
      counter+=!(sum%arr[i]);
    }
  }

  for(i=0; i<n; i++)
    cout<<arr[i]<<' ';
}
