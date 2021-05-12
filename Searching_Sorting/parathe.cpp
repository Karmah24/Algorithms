#include <bits/stdc++.h>
using namespace std;

#define fori(i, n) for (ll i = 0; i < n; i++)
#define ll long long
//=======================

class Solution {
public:
    ll solve(ll arr[], int n, int p) {

        ll lo = 0, hi = LLONG_MIN;
        fori (i, n) hi = max(hi, arr[i]);
        hi = (p * (p + 1) * hi) / 2;
        ll res = LLONG_MAX;

        while (lo <= hi) {
            ll mid = (lo + hi) / 2, parathe = 0;
            int i = 0;
            while (parathe < p && i < n) {
                int x = 1;
                while (x * (x + 1) <= (mid * 2) / arr[i]) x++;
                parathe += --x;
                i++;
            }
            if (parathe >= p) {
                res = mid;
                hi = mid - 1;
                continue;
            }
            lo = mid + 1;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
	    int n, m;
	    cin >> m >> n;
	    ll arr[n];
	    fori (i, n) cin >> arr[i];
	    Solution obj;
	    cout << obj.solve(arr, n , m) << endl;
    }
}
