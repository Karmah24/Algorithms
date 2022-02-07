#include <bits/stdc++.h>
using namespace std;
// #define int long long
//=======================
const int N = 25, M = 2e5;
int spt[N][M];
void build_spt(vector<int> &arr) {
    int m = arr.size();
    int n = floor(log2(m));
    for (int i = 0; i < m; i++) spt[0][i] = arr[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            spt[i][j] = gcd(spt[i - 1][j], spt[i - 1][j + (1 << (i - 1))]);
        }
    }
}
int get_gcd(int l, int r) {
    int p = floor(log2(r - l + 1));
    int k = 1 << p;
    return gcd(spt[p][l], spt[p][r - k + 1]);
}

vector<int> solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &e: arr) cin >> e;
    build_spt(arr);
    vector<pair<int, int>> segs;
    for (int l = 0; l < n; l++) {
        int lo = l, hi = n - 1;
        while (lo <= hi) {
            int r = (lo + hi) / 2;
            int g = get_gcd(l, r), len = r - l + 1;
            if (g == len) {
                segs.push_back({l, r});
                break;
            }
            else if (g < len) hi = r - 1;
            else lo = r + 1;
        }
    }
    sort(segs.begin(), segs.end(), [](pair<int, int> a, pair<int, int> b){
        return a.second < b.second || a.first < b.first;
    });
    vector<int> changes;
    int r_m = -1;
    for (int i = 0; i < segs.size(); i++) {
        if (r_m >= segs[i].first) continue;
        r_m = segs[i].second;
        changes.push_back(r_m);
    }
    vector<int> res(n);
    int x = 0, i = 0;
    for (auto &e: changes) {
        while (i < e) res[i++] = x;
        x++;
    }
    while (i < n) res[i++] = x;
    return res;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    int T = 1;
    // cin >> T;
    while (T--) {
        for (auto &e: solve()) cout << e << " ";
    }
    return 0;
}