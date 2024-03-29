// Online C++ compiler to run C++ program online
#include <stdio.h>
#include <string.h>

int count;

int recursion(const char *s, int l, int r){
    count++;
    printf("check!, %d\n", count);
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(){
    int t, var;
    char str[10001];
    scanf("%d", &t);
    while(t--) {
        count = 0;
        scanf("%s", str);
        var=isPalindrome(str);
        printf("%d %d\n", var, count); // 1
    }
    return 0;
}
