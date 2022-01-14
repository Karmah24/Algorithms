#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

void solve() {
    
    int n;
    cin >> n;
    vector<int> arr(n);

    int l = -1, r;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] != i + 1) {
            if (l == -1) l = i;
            else r = i;
        }
    }
    if (l == -1) {
        cout << "yes\n" << "1 1";
        return;
    }
    reverse(arr.begin() + l, arr.begin() + r + 1);

    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            cout << "no";
            return;
        }
    }
    cout << "yes\n" << l + 1 << " " << r + 1; 
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}