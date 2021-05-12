#include<bits/stdc++.h>

using namespace std;
#define fori(i, n) for (int i = 0; i < n; i++)
//=======================

int maxProfit(int K, int N, int p[]) {
    int pr[2][N];
    for (int& e: pr[0]) e = 0;
    pr[1][0] = 0;

    for (int t = 1; t <= K; t++) {

        int m = INT_MIN;
        for (int d = 1; d < N; d++) {
            m = max(m, pr[0][d - 1] - p[d - 1]);
            pr[1][d] = max(pr[1][d - 1], m + p[d]);
        }

        for (int i = 1; i < N; i++) pr[0][i] = pr[1][i];
    }
    return pr[0][N - 1];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int T = 1;
    cin >> T;
    while (T--) {
        int K, N;
        cin >> K >> N;
        int p[N];
        fori (i, N) cin >> p[i];
        cout << maxProfit(K, N, p);
    }
    return 0;
}