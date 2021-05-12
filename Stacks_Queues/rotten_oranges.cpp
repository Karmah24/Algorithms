#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for (int i = 0; i < n; i++)
const int N = 101, M = N;
//=======================
int arr[N][M];

struct pt {
    int r, c, t;
    pt(int r, int c, int t) {
        this->r = r, this->c = c, this->t = t;
    }
};

void solve() {
    int R, C;
    cin >> R >> C;
    queue<pt> queue;
    loop (i, R) {
        loop (j, C) {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
                queue.push(pt(i, j, 0));
        }
    }
    int time = 0;
    while (!queue.empty()) {
        pt p  = queue.front();
        int r = p.r, c = p.c;
        if (r - 1 >= 0 && arr[r - 1][c] == 1) {
            time = p.t + 1;
            arr[r - 1][c] = 2;
            queue.push(pt(r - 1, c, p.t + 1));
        }
        if (r + 1 < R && arr[r + 1][c] == 1) {
            time = p.t + 1;
            arr[r + 1][c] = 2;
            queue.push(pt(r + 1, c, p.t + 1));
        }
        if (c - 1 >= 0 && arr[r][c - 1] == 1) {
            time = p.t + 1;
            arr[r][c - 1] = 2;
            queue.push(pt(r, c - 1, p.t + 1));
        }
        if (c + 1 < C && arr[r][c + 1] == 1) {
            time = p.t + 1;
            arr[r][c + 1] = 2;
            queue.push(pt(r, c + 1, p.t + 1));
        }
        queue.pop();
    }
    loop (i, R)
        loop (j, C)
            if (arr[i][j] == 1)
                time = -1;
    cout << time << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}