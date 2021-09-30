#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

int input_words(char *[]);
void print_words(int, double*);
int compare_word(const void *, const void *);
int compare_int(const void*, const void*);
int compare_double(const void*,const void*);

int arr_int[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
double arr_double[10] = { 10.9, 9.8, 8.7, 7.6, 6.5, 5.4, 4.3, 3.2, 2.1, 1.1 };
char *arr_word[10] = { "apple", "purple", "song", "name", "green", "brown", "yellow", "moon", "red", "zero" };

int main(void) {
   char *word_p[N];
   int num_word = N;

   //num_word = input_words(word_p);
   qsort(arr_double, N, sizeof(double), compare_double);
   print_words(N, arr_double);

   for (int i = 0; i < num_word; i++)
      free(word_p[i]);

   return 0;
}

int input_words(char *words[]) {
   int num = 0;
   char temp[21];

   for (int i = 0; i < 10; i++) {
      printf("%d번째 단어 입력 : ", i + 1);
      scanf("%[^\n]", temp);
      getchar();

      words[num] = (char *)calloc(strlen(temp) + 1, sizeof(char));
      strcpy(words[num], temp);

      num++;
   }
   return num;
}

void print_words(int num, double words[]) {
   for (int i = 0; i < num; i++)
      printf("%lf ", words[i]);

   printf("\n");
}

int compare_word(const void *p, const void *q) {
   return strcmp(*(char **)p, *(char **)q);
}

int compare_int(const void *p, const void *q){
  return (*(int*)p)<(*(int*)q)?-1:1;
}

int compare_double(const void *p, const void *q){
  return (*(double*)p)<(*(double*)q)?-1:1;
}
