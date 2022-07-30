// 3.48.54
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;
ll add(ll x, ll y) {return ((x % MOD) + (y % MOD)) % MOD;}

int solve(int n, int m, int arr[]) {

    vector<int> prev(m + 1, 0);
    if (arr[0] == 0) for (int i = 0; i < m; i++) prev[i] = 1;
    else prev[arr[0] - 1] = 1;

    for (int i = 1; i < n; i++) {

        for (int j = 0; j < m; j++) {

            if (arr[i] != 0) j = arr[i] - 1;

            prev[j] = add(prev[j], j == 0 ? 0 : prev[j - 1]);
            prev[j] = add(prev[j], prev[j]);
            prev[j] = add(prev[j], j == m - 1 ? 0 : prev[j + 1]);

            if (arr[i] != 0) break;
        }
        for (int j = 0; j < m; j++) {
            prev[j] = prev[j];
            prev[j] = 0;
        }
    }
    if (arr[n - 1] != 0) return prev[arr[n - 1] - 1];
    ll res = 0;
    for (int j = 0; j < m; j++) res = add(res, prev[j]);
    return res;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << solve(n, m, arr);
}