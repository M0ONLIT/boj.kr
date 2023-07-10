#include<iostream>
using namespace std;

class A{
public:
  int a=1;

  void p(){
    cout<<a;
  }
};
int a=2;

int main(){
  A b;
  b.p();
}
