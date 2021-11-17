#include <stdio.h>

typedef struct{
  char name[10];
  int id, age, pay;
} employee;

int main(void){
  employee x;
  int count=0;
  FILE *fp=fopen("employee.bin", "wb");
  while(scanf("%s %d %d %d", x.name, &x.id, &x.age, &x.pay)==4){
    fwrite(&x, sizeof(employee), 1, fp);
  }
  fclose(fp);
}
