#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
//=======================

unordered_map<int, vector<int>> divisors;

vector<int> getDivisors(int n) {

    if (!divisors[n].empty()) return divisors[n];

    for (int i = 1; i * i <= n; i++) {

        if (n % i != 0) continue;
        divisors[n].push_back(i);
        if (i * i != n) divisors[n].push_back(n / i);
    }
    return divisors[n];
}

ll solve() {

    int n;
    cin >> n;
    vector<pair<int, int>> arr(n + 1);

    for (int i = 1; i < n + 1; i++) {

        int inp;
        cin >> inp;
        int g = __gcd(inp, i);
        arr[i] = {inp / g, i / g};
    }

    unordered_map<int, unordered_map<int, int>> dp;
    ll res = 0;

    for (int i = 1; i < n + 1; i++) {

        int req = arr[i].second;
        for (auto available: getDivisors(arr[i].first)) {
            res += dp[req][available];
            dp[available][req]++;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int T = 1;
    cin >> T;
    while (T--) {
        cout << solve() << ln;
    }
    return 0;
}