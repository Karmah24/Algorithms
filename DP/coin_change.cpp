#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;
#define loop(i, n) for (int i = 0; i < n; i++)
typedef vector<int>		vi;
const int N = 1e4, M = N;
//=======================
long dp[N][M];
vi v;

long solve(int n, int i) {
    // if (n < v[i])
    //     return 0;
    if (dp[n][i] != -1)
        return dp[n][i];
    if (i == v.size() - 1) {
        if (n % v[i] == 0)
            dp[n][i] = 1;
        else dp[n][i] = 0;
        return dp[n][i];
    }
    if (n == 0) return 1;
    long s = 0;
    for (int j = 0; n >= v[i] * j; j++) {
        int a = n - v[i] * j;
        s += solve(a, i + 1);
    }
    dp[n][i] = s;
    return s;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m;
        loop (i, m) {
            cin >> k;
            v.push_back(k);
        }
        auto start = high_resolution_clock::now();
        loop (i, n + 1) loop (j, m) dp[i][j] = -1;
        cout << solve(n, 0) << endl;
        v.clear();
        auto stop = high_resolution_clock::now();
        cout << endl << duration_cast<microseconds>(stop - start).count();
    }
    return 0;
}