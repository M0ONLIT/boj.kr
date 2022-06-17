#include<stdio.h>

int n,k,ans,a[10005];

long long p(int x){
  int i;
  long long ans=0;
  for(i=0;i<n;i++)
    ans+=a[i]/x;
  return ans;
}

int main(){
  int i;
  long long start=1,end,mid;
  scanf("%d%d",&n,&k);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    end=end<a[i]?a[i]:end;
  }
  while(start<=end){
    mid=(start+end)/2;
    if(p(mid)>=k){
      ans=mid;
      start=mid+1;
    }
    else
      end=mid-1;
  }
  printf("%d",ans);
}
