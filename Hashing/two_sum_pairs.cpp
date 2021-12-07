#include <bits/stdc++.h>
using namespace std;
#define ll long long
//=======================

ll solve() {
    
    int n;
    cin >> n;
    vector<ll> arr(n);
    ll sum = 0;
    for (ll &e: arr) {
        cin >> e;
        sum += e;
    }
    if ((2 * sum) % n != 0) return 0;
    ll t = (2 * sum) / n, res = 0;
    unordered_map<ll, ll> freq;
    for (ll e: arr) {

        res += freq[t - e];
        freq[e]++;
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