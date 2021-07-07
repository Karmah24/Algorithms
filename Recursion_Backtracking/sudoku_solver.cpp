#include<bits/stdc++.h>
using namespace std;

int sudoku[9][9];

bool is_complete(int &r, int &c) {
    for (r = 0; r < 9; r++) {
        for (c = 0; c < 9; c++)
        if (sudoku[r][c] == 0) return false;
    }
    return true;
}

bool is_safe(int num, int r, int c) {
    
    for (int i = 0; i < 9; i++) {
        if (sudoku[r][i] == num) return false;
    }
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][c] == num) return false;
    }

    int box_r = r - r % 3;
    int box_c = c - c % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[i + box_r][j + box_c] == num) return false;
        }
    }
    return true;
}

bool solve() {
    int r, c;
    if (is_complete(r, c)) return true;

    for (int num = 1; num <= 9; num++) {
        if (is_safe(num, r, c)) {

            sudoku[r][c] = num;

            if (solve())
                return true;

            sudoku[r][c] = 0;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) cin >> sudoku[i][j];
    }
    if (solve())
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) cout << sudoku[i][j] << " ";
            cout << endl;
        }
    else cout << "No solution exists";
}