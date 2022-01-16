#include <bits/stdc++.h>
using namespace std;
#define ll long long
//=======================

ll solve() {
    
    int n, M = 0, x;
    cin >> n;
    unordered_set<int> present;
    while (n--) {
        cin >> x;
        M = max(M, x);
        present.insert(x);
    }
    ll res = 0;
    for (int i = 1; i < M; i++) {
        if (present.count(i)) continue;
        int g = 0;
        for (int mult = i; mult <= M; mult += i) {
            if (present.count(mult)) g = gcd(g, mult);
        }
        if (g == i) res++;
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

        cout << solve() << '\n';
    }
    return 0;
}