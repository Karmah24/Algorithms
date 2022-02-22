#include <bits/stdc++.h>
using namespace std;
//================================================================
int n;
vector<int> a;

bool isVal(int i) {
    if (i <= 0 || i >= n - 1) return false;
    return a[i - 1] > a[i] && a[i] < a[i + 1];
}
bool isHill(int i) {
    if (i <= 0 || i >= n - 1) return false;
    return a[i - 1] < a[i] && a[i] > a[i + 1];
}
int cnt(int i) {
    return isVal(i - 1) + isHill(i - 1) + isVal(i) + isHill(i) + isVal(i + 1) + isHill(i + 1);
}
int check(int i) {
    int curr = cnt(i);
    int temp = a[i];
    int res = 0;
    if (i > 0) {
        a[i] = a[i - 1];
        res = curr - cnt(i);
    }
    if (i < n - 1) {
        a[i] = a[i + 1];
        res = max(res, curr - cnt(i));
    }
    a[i] = temp;
    return res;
}
int solve() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int t = 0;
    for (int i = 1; i < n - 1; i++) {
        if (isHill(i) || isVal(i)) t++;
    }
    int res = 0;
    for (int i = 1; i < n - 1; i++) {
        res = max(res, check(i));
    }
    return t - res;
}
signed main() {
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