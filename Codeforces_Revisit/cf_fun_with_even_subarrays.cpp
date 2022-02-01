#include <bits/stdc++.h>
using namespace std;
#define int long long
//=======================

int solve() {
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &e: arr) cin >> e;
    int i = n - 2, res = 0;
    while (i >= 0) {
        while (arr[i] == arr[n - 1] && i >= 0) i--;
        if (i >= 0) res++;
        i -= n - i - 1;
    }
    return res;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}