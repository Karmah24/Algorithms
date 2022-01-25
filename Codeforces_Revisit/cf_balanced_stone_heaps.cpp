#include <bits/stdc++.h>
using namespace std;
#define ll long long
//=======================

bool check(int x, vector<int> &h) {

    int n = h.size();
    vector<int> add(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        int extra = h[i] + add[i] - x;
        if (extra < 0) return false;
        if (i < 2) continue;
        int d = (min(h[i], extra) / 3);
        add[i - 1] += d, add[i - 2] += d * 2;
    }
    return true;
}
ll solve() {
    
    int n, m = 1, M = 1;
    cin >> n;
    vector<int> h(n);
    for (auto &e: h) {
        cin >> e;
        m = min(m, e);
        M = max(M, e);
    }
    int lo = m, hi = M, res;
    while (lo <= hi) {
        int curr = (lo + hi) / 2;
        if (check(curr, h)) {
            res = curr;
            lo = curr + 1;
        }
        else hi = curr - 1;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int T = 1;
    cin >> T;
    while (T--) {
        
        cout << solve() << '\n';
    }
    return 0;
}