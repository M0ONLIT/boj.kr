#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int n;

// 스도쿠가 유효한지 검사하는 함수
bool isValid(vector<vector<int>>& board, int row, int col, int num, int n) {
    int sqrt_n = sqrt(n);
    int box_row_start = row/sqrt_n*sqrt_n;
    int box_col_start = col/sqrt_n*sqrt_n;

    // 행과 열에서 num이 있는지 검사
    for (int x = 0; x < n; x++) {
        if (board[row][x] == num || board[x][col] == num) {
            return false;
        }
    }

    // 작은 박스에서 num이 있는지 검사
    for (int i = 0; i < sqrt_n; i++) {
        for (int j = 0; j < sqrt_n; j++) {
            if (board[i + box_row_start][j + box_col_start] == num) {
                return false;
            }
        }
    }

    return true;
}

// 백트래킹으로 스도쿠를 해결하는 함수
void solveSudoku(vector<vector<int>>& board, int idx, int& solutions_count) {
    if(solutions_count>1) return;
    int row = idx/n;
    int col = idx%n;
    bool isEmpty = true;

    // 빈 공간이 없으면 스도쿠가 해결됨
    if (idx==n*n) {
        solutions_count++;
        return;
    }

    // 1부터 n까지의 숫자를 시도
    for (int num = 1; num <= n; num++) {
        if (isValid(board, row, col, num, n)) {
            board[row][col] = num;
            solveSudoku(board, idx+1, solutions_count);
            board[row][col] = 0;
        }
    }
}
int main() {
    cin >> n; n*=n;

    vector<vector<int>> board(n, vector<int>(n));
    vector<vector<int>> cpy(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];

        }
    }
    int ansmin=n*sqrt(n)*(sqrt(n)-1)-10;
    int solutions_count = 0;

    int s=ansmin, e=n*n-1;
    while(s<e){
        int mid=(s+e)/2;
        cout<<s<<' '<<e<<'\n';
        for(int ptr=ansmin; ptr<n*n; ptr++){
            int i=ptr/n, j=ptr%n;
            cpy[i][j]=0;
        }
        for(int ptr=ansmin; ptr<=mid; ptr++){
            int i=ptr/n, j=ptr%n;
            cpy[i][j]=board[i][j];
        }
        solutions_count = 0;
        solveSudoku(cpy, mid+1, solutions_count);
        if (solutions_count == 1){
            e=mid;
        }
        else{
            s=mid+1;
        }
    }
    cout<<s;
    return 0;
}
