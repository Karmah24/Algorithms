#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
//=======================

ll solve() {
    
    ll n, H;
    cin >> n >> H;
    ll m1 = 0, m2 = 0;
    for (int i = 0; i < n; i++) {

        ll inp;
        cin >> inp;
        if (m1 <= inp) {
            m2 = m1;
            m1 = inp;
        }
        else if (m2 < inp) m2 = inp;
    }
    ll res = 2 * (H / (m1 + m2));
    res += H % (m1 + m2) != 0;
    res += (H % (m1 + m2)) > m1;
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
        
        cout << solve() << ln;
    }
    return 0;
}