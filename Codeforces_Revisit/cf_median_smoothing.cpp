#include <bits/stdc++.h>
using namespace std;
#define ll long long
//=======================

void solve() {
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    vector<pair<int, int>> stable;
    bool prev_stable = true;
    int j = 0;

    for (int i = 1; i < n - 1; i++) {
        if (arr[i] == arr[i - 1] || arr[i] == arr[i + 1]) {
            prev_stable = true;
        }
        else {
            if (prev_stable) stable.push_back({j, i - 1});
            j = i + 1;
            prev_stable = false;
        }
    }
    stable.push_back({j, n - 1});
    int res = 0;
    for (int i = 0; i < stable.size() - 1; i++) {

        int l = stable[i].second, r = stable[i + 1].first;
        res = max(r - l - 1, res);
        while (l < r - 1) {
            arr[l + 1] = arr[l];
            arr[r - 1] = arr[r];
            l++, r--;
        }
    }
    cout << (res + 1) / 2 << '\n';
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int T = 1;
    // cin >> T;
    while (T--) {
        
        solve();
    }
    return 0;
}