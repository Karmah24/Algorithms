#include <bits/stdc++.h>
using namespace std;
#define ll long long
//=======================

int n, l, k;
vector<int> a, d;
vector<vector<ll>> dp;

ll f(int sp, int i, int k) {

    if (i == n + 1) return 0;
    if (dp[i][k] != -1) return dp[i][k];

    int ifin, ifout = f(a[i], i + 1, k);
    ifin = k > 0 ? f(sp, i + 1, k - 1) : INT_MAX;

    return dp[i][k] = min(ifin, ifout) + sp * (d[i] - d[i - 1]);
}
ll solve() {
    
    cin >> n >> l >> k;
    a.resize(n); 
    d.resize(n + 1);
    for (int i = 0; i < n; i++) cin >> d[i];
    d[n] = l;
    for (int i = 0; i < n; i++) cin >> a[i];

    dp.assign(n + 1, vector<ll>(k + 1, -1));
    return f(a[0], 1, k);
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int T = 1;
    // cin >> T;
    while (T--) {
        
        cout << solve() << '\n';
    }
    return 0;
}