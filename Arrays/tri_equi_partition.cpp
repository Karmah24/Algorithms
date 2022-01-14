#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
//=======================

ll solve() {
    
    int n;
    cin >> n;
    vector<int> arr(n);
    ll s = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s += arr[i];
    }
    if (s % 3 != 0) return 0;
    ll res = 0, cnt = 0, curr = 0;
    for (int i = 0; i < n - 1; i++) {
        
        curr += arr[i];
        if (curr == (2 * s) / 3) res += cnt;
        if (curr == s / 3) cnt++;
    }
    return res;
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
        
        cout << solve() << ln;
    }
    return 0;
}