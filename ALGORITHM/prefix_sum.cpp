#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class prefix_sum{
public:
  vector<int> s;
  prefix_sum(){};
  prefix_sum(vector<int> &v){
    s=vector<int>(1);
    for(int& i: v){
      s.push_back(i+s.back());
    }
  }
  int sum(int x, int y){
    return s[y+1]-s[x];
  }
};


prefix_sum S;

int main(){
  vector<int> v={1, 2, 3};
  S=prefix_sum(v);
}
