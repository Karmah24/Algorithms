#include <bits/stdc++.h>
using namespace std;

int dig(int n) {
    int d = 0;
    while (n) {
        d++;
        n /= 10;
    }
    return d;
}

vector<int> dp;

int solve(int n) {

    if (dp[n - 1] != -1) return dp[n - 1];
    int d = dig(n);
    if (d == 1) return dp[n - 1] = 1;

    int res = INT_MAX;

    for (int i = 1; i <= d; i++) {

        int toRemove = (int)(n / (pow(10, d - i))) % 10;
        if (toRemove != 0) res = min(res, solve(n - toRemove) + 1);
    }
    return dp[n - 1] = res;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    dp = vector<int>(n, -1);
    cout << solve(n);
}