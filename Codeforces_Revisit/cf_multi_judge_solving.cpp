#include <bits/stdc++.h>
using namespace std;
#define ll long long
//=======================

ll solve() {

    int n;
    ll k, res = 0;
    cin >> n >> k;
    k *= 2;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    
    auto itr = arr.begin();
    while (k < arr.back()) {
        itr = upper_bound(itr, arr.end(), k);
        ll curr = k;
        if (itr != arr.begin()) curr = *prev(itr) * 2;
        k = max(curr, k);
        int next = ceil(log2(ceil(*itr / (double)k)));
        res += next;
        k *= pow(2, next);
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