#include <bits/stdc++.h>
using namespace std;
#define ll long long
//=======================

vector<ll> solve() {

    int n, x;
    cin >> n;
    vector<ll> cnt(n + 1, 0), res(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> x;
        cnt[x]++;
    }
    stack<ll> ext;
    vector<ll> ext_cnt(n + 1, 0);
    res[0] = cnt[0];
    if (cnt[0] > 1) {
        ext_cnt[0] = cnt[0] - 1;
        ext.push(0);
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i - 1] == 0 && ext.empty() || res[i - 1] == -1) res[i] = -1;
        else {
            res[i] = res[i - 1] - cnt[i - 1] + cnt[i];
            if (cnt[i - 1] == 0) {
                ll tp = ext.top();
                res[i] += i - 1 - tp;
                if (--ext_cnt[tp] == 0) ext.pop();
            }
        }
        if (cnt[i] > 1) {
            ext_cnt[i] = cnt[i] - 1;
            ext.push(i);
        }
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

        for (auto &e: solve()) cout << e << " ";
        cout << '\n';
    }
    return 0;
}