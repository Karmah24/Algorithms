#include <bits/stdc++.h>
using namespace std;

#define fori(i, n) for (ll i = 0; i < n; i++)
#define ll long long
//=======================

class Solution {
public:
    ll findPages(ll arr[], int n, int m) {

        sort(arr, arr + n);
        ll lo = arr[0], hi = arr[n - 1];
        ll res = INT_MIN;

        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            int x = 1, x_pos = 0, i = 1;

            while (x < m && i < n) {
                if (arr[i] - arr[x_pos] < mid) {
                    i++;
                    continue;
                }
                x_pos = i++;
                x++;
            }            
            if (x != m) {
                hi = mid - 1;
                continue;
            }
            res = mid;
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
	    cin >> n >> m;
	    ll arr[n];
	    fori (i, n) cin >> arr[i];
	    Solution obj;
	    cout << obj.findPages(arr, n , m) << endl;
    }
}
