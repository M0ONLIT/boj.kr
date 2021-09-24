#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<tuple>
using namespace std;

typedef long long ll;

typedef struct{
  ll x, y;
} point;

int n;
vector<point> stack;
point p[100005];

ll ccw(point p1, point p2, point p3){
  return (p3.y-p1.y)*(p2.x-p1.x)+(p1.y-p2.y)*(p3.x-p1.x);
} //시계: -, 반시계: +, 일직선: 0

int main(){

  int i,j;
  cin>>n;
  for(i=0; i<n; i++)
    cin>>p[i].x>>p[i].y;


}
