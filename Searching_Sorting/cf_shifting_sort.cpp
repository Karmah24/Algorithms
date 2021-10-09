#include <bits/stdc++.h>
using namespace std;

void solve() {
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<vector<int>> res;

    for (int i = 0; i < n; i++) {

        int max_idx = max_element(arr.begin(), arr.end()) - arr.begin();
        arr.erase(arr.begin() + max_idx);
        if (max_idx == n - 1 - i) continue;
        res.push_back({max_idx + 1, n - i});
    }
    cout << res.size() << '\n';
    for (auto move: res) {
        cout << move[0] << " " << move[1] << " " << 1 << '\n';
    }
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
        
        solve();
    }
    return 0;
}