#include <stdio.h>
int num [20000]={};
int i;
int number;
int self()
{
   for(i = 0; i<10000; i++) {
      number  = i + i%10 + i/10%10 + i/100%10 + i/1000%10;
      num[number] = 1;
   }
}
int main() {
  int j = 1;
  self();
  while(j<10001) {
     if(num[j]!=1) {
        printf("%d\n", j);
     }
     j++;
  }
  return 0;
}
