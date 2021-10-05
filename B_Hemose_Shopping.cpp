#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
//=======================

bool solve() {
    
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    bool st = true;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            st = false;
            break;
        }
    }
    if (!st && x >= n) return false;
    return true;
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
        
        if (solve()) cout << "YES" << ln;
        else cout << "NO" << ln;
    }
    return 0;
}