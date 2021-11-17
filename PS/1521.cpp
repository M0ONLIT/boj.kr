#include<iostream>
#include<stdio.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
ld memory[40500];
int visit[40500];
int arr[10], facto[10];

int toint(){
  int ans=0, i, j;
  for(i=0; i<n; i++){
    int count=0;
    for(j=i+1; j<n; j++)
      count+=arr[i]>arr[j];
    ans+=count*facto[n-i-1];
  }
  return ans;
}


void swap(int &a, int &b){
  a=a^b; b=a^b; a=a^b;
}

ld f(int state){
  int i, j, t=0;
  ld ans=0;

  if(visit[state]++)
    return memory[state];

  for(i=0; i<n; i++) for(j=i+1; j<n; j++)
    if(arr[i]>arr[j]){
      swap(arr[i], arr[j]);
      ans+=f(toint()); t++;
      swap(arr[i], arr[j]);
    }
  memory[state]=ans/t+1;
  return memory[state];
}

int main(){
  int i;
  for(i=0; i<8; i++)
    facto[i]=i?i*facto[i-1]:1;
  visit[0]=1;

  scanf("%d", &n);
  for(i=0; i<n; i++)
    scanf("%d", &arr[i]);
  printf("%.16Lf", f(toint()));
}
