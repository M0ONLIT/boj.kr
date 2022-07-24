#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<tuple>
using namespace std;

typedef long long ll;
typedef long double ld;
int n;
ld ans[200005];

vector<pair<int, int>> balloon;
vector<pair<ld, ld>> stack;

ld pow2(ld x){
  return pow(x, 2);
}

int main(){
  int i, j;
  scanf("%d", &n);
  for(i=0; i<n; i++){
    pair<int, int> x;
    scanf("%d%d", &x.first, &x.second);
    balloon.push_back(x);
  }
  sort(balloon.begin(), balloon.end());

  for(i=0; i<n; i++){
    ld p1, p2, r1, r2;
    p2=balloon[i].first; //좌표
    r2=balloon[i].second; //크기

    for(j=stack.size()-1; j>=0; j--){
      tie(p1, r1)=stack[j];
      r2=min(r2, pow2(p2-p1)/(4*r1));
      if(r2<=r1)
          break;
    }

    ans[i]=r2;
    while(!stack.empty() && stack.back().second<=r2)
      stack.pop_back();
    stack.push_back(make_pair(p2, r2));
  }
  for(i=0; i<n; i++)
    printf("%.3Lf\n", ans[i]);

}
