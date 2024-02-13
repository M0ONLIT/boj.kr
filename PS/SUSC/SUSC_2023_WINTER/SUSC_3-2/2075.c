#include <stdio.h>

#define MAX_N 1501

int arr[MAX_N][MAX_N];
int ptr[MAX_N];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &arr[i][j]);
        }
        ptr[i] = n - 1;
    }
    int ans = 0;
    for (int k = 0; k < n; ++k) {
        int max_val = -2e9, idx = -1;
        for (int i = 0; i < n; ++i) {
            if (arr[ptr[i]][i] > max_val) {
                max_val = arr[ptr[i]][i];
                idx = i;
            }
        }
        ans = max_val;
        ptr[idx]--;
    }
    printf("%d\n", ans);
    return 0;
}
