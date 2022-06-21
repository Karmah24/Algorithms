#include <bits/stdc++.h>
using namespace std;
#define ll long long
//=======================

ll solve() {
    
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    unordered_map<int, int> freq_a, freq_b;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        freq_a[a[i]]++;
        freq_b[b[i]]++;
    }
    ll res = ((ll)n * (n - 1) * (n - 2)) / 6;
    for (int i = 0; i < n; i++) {
        res -= (ll)(freq_a[a[i]] - 1) * (freq_b[b[i]] - 1);
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
    cin >> T;
    while (T--) {       
        cout << solve() << '\n';
    }
    return 0;
}