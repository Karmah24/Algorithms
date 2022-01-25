#include <bits/stdc++.h>
using namespace std;
//=======================

void solve() {

    int n;
    cin >> n;
    vector<int> arr(n), cnt(n + 1), vis(n + 1), res;
    for (int &e: arr) {
        cin >> e;
        cnt[e]++;
    }
    int mex = 0, l = 0;
    for (int r = 0; r < n; r++) {

        cnt[arr[r]]--;
        vis[arr[r]] = true;

        while (vis[mex]) mex++;
        if (cnt[mex] == 0) {
            res.push_back(mex);
            for (int j = r; j >= l; j--) vis[arr[j]] = false;
            l = r + 1;
            mex = 0;
        }
    }
    cout << res.size() << '\n';
    for (int &e: res) cout << e << " ";
    cout << '\n';
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