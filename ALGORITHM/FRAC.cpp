#include<iostream>
#include<cmath> 
typedef long long ll;
using namespace std;
ll gcd(ll a, ll b){
  return b?gcd(b, a%b):a;
}
class Fraction{
public: ll num, denom;
  Fraction(int x){
    num=x, denom=1;
  };
  Fraction(int x, int y){
    num=x, denom=y;
    yakbun();
  }
  Fraction(Fraction &frac){
    num=frac.num, denom=frac.denom;
    yakbun();
  }
  void yakbun(){
    ll GCD=gcd(num, denom); 
    num/=GCD, denom/=GCD; 
  }
  Fraction inverse(){
    Fraction frac(denom, num);
    return frac; 
  } 
  Fraction operator+(Fraction x){
    ll p=num*x.denom+denom*x.num, q=denom*x.denom;
    Fraction frac(p, q);
    return frac;
  } 
  Fraction operator*(Fraction x){ 
    ll p=num*x.num, q=denom*x.denom; 
    Fraction frac(p, q); 
    return frac; 
  } 
  Fraction operator/(Fraction x){
    ll p=num*x.denom, q=denom*x.num;
    Fraction frac(p, q); 
    return frac;
  }
  int operator<(Fraction x){
    return num*x.denom<x.num*denom;
  } 
  int operator>(Fraction x){
    return num*x.denom>x.num*denom;
  }
  int operator==(Fraction x){
    return num*x.denom==x.num*denom;
  } 

}; 
