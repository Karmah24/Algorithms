#include <bits/stdc++.h>
using namespace std;


int solve() {
    
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    sort(a, a + n);
    sort(b, b + n);

    int t = 1;
    int i = n - 1, j = n - 1;
    bool t1 = 0, t2 = 0; 
    while (i >= 0 && j >= 0) {

        if (t % 2 != 0) {
            if (a[i] > b[j]) return t2 == 0 ? a[i] - b[j] : 0;
            else if (a[i] == b[j]) t1 = 1;
            j--;
        }
        else {
            if (b[j] > a[i]) return t1 == 0 ? a[i] - b[j] : 0;
            else if (b[j] == a[i]) t2 = 1;
            i--;
        }
        t++;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed);

    int T = 1;
    // cin >> T;
    while (T--) {
        cout << solve() ;
    }
    return 0;
}