// given m apartment sizes and n applications with desired size and k wiggle room
// rent out max possible apartments

#include <bits/stdc++.h>
using namespace std;

int solve() {

    int n, m, k;
    cin >> n >> m >> k;
    int a[n], b[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    // allot the smallest acceptable room to each applicant
    // starting from the one with the smallest requirement 
    sort(a, a + n); 
    sort(b, b + m);

    int j = 0, res = 0;
    for (int i = 0; i < n && j < m; i++) {

        int lb = lower_bound(b + j, b + m, a[i] - k) - b;
        if (a[i] - k <= b[lb] && b[lb] <= a[i] + k) {
            res++;
            j = lb + 1;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed);

    int T = 1;
    // cin >> T;
    while (T--) {
        cout << solve();
    }
    return 0;
}