#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int n;
vector<int> a;

void solve(map<int, int> &odd, map<int, int> &even) {
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) even[a[i]]++;
        else odd[a[i]]++;
    }
}
bool solve() {

    cin >> n;
    a.resize(n);
    for (auto &e: a) cin >> e;
    map<int, int> odd, even;
    solve(odd, even);
    sort(a.begin(), a.end());
    map<int, int> odd_sorted, even_sorted;
    solve(odd_sorted, even_sorted);
    for (auto &[k, v]: odd) {
        if (odd_sorted[k] != v) return false;
    }
    for (auto &[k, v]: even) {
        if (even_sorted[k] != v) return false;
    } 
    return true;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        if (solve()) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
    return 0;
}