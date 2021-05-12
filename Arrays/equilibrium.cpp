#include<bits/stdc++.h>

using namespace std;
#define fori(i, n) for (int i = 0; i < n; i++)
const int N = 3e5, M = N;
//=======================
int arr[N];

void solve() {
    int n;
    cin >> n;
    fori (i, n) cin >> arr[i];
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    int a[n], b[2];
    a[n - 1] = b[0] = 0;
    for (int i = n - 2; i >= 0; i--)
        a[i] = a[i + 1] + arr[i + 1];
    for (int i = 1; i < n; i++) {
        b[1] = b[0] + arr[i - 1];
        if (b[1] == a[i]) {
            cout << i + 1 << endl;
            return;
        }
        b[0] = b[1];
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}