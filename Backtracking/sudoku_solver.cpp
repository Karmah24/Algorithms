#include<bits/stdc++.h>

using namespace std;
#define fori(i, n) for (int i = 0; i < n; i++)
const int N = 9, M = N;
//=======================
int sudoku[N][M];

bool is_complete(int &r, int &c) {
    for (r = 0; r < N; r++)
        for (c = 0; c < N; c++)
        if (sudoku[r][c] == 0)
            return false;
    return true;
}

bool is_safe(int num, int r, int c) {
    fori (i, N)
        if (sudoku[r][i] == num)
            return false;
    fori (i, N)
        if (sudoku[i][c] == num)
            return false;
    
    int box_r = r - r % 3;
    int box_c = c - c % 3;
    fori (i, 3)
        fori (j, 3) 
            if (sudoku[i + box_r][j + box_c] == num) 
                return false; 
    
    return true; 
}

bool solve() {
    int r, c;
    if (is_complete(r, c))
        return true;
    
    for (int num = 1; num <= 9; num++) {
        if (is_safe(num, r, c)) {
            sudoku[r][c] = num;

            // if (num == 9 && sudoku[r][c] == 0)
            //     return false; 
            if (solve())
                return true;
            
            sudoku[r][c] = 0;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        fori (i, N) fori (j, N) cin >> sudoku[i][j];
        if (solve())
            fori (i, N) {
                fori (j, N) cout << sudoku[i][j] << " ";
                cout << endl;
            }
        else cout << "No solution exists";
    }
    return 0;
}