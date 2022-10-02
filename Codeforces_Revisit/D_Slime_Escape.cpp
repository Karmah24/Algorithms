#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

void testcase() {

    int n, k;
    cin >> n >> k;
    k--;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int h = a[k];
    int i = k, j = k;
    bool res = true;
    while (i > 0 && j < n - 1) {

        int h1 = h, h2 = h, l = i, r = j;
        int max1 = h, max2 = h, idx1 = i, idx2 = j;

        while (l > 0 && h1 + a[l - 1] >= 0) {

            l--;
            h1 += a[l];
            if (h1 > max1) {

                max1 = h1;
                idx1 = l;
            }
        }
        while (r < n - 1 && h2 + a[r + 1] >= 0) {

            r++;
            h2 += a[r];
            if (h2 > max2) {

                max2 = h2;
                idx2 = r;
            }
        }
        if (l == 0 || r == n - 1) break;

        if (idx1 == i && idx2 == j) {

            res = false;
            break;
        }
        if (idx1 < i) {

            i = idx1;
            h = max1;
        }
        else {

            j = idx2;
            h = max2;
        }
    }
    if (res) cout << "YES";
    else cout << "NO";
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	  freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
