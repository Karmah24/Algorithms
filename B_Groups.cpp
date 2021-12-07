#include <bits/stdc++.h>
using namespace std;
#define ll long long
//=======================

bool solve() {

    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(15));

    for (int i = 0; i < n; i++) {

        int j = 0;
        for (; j < 5; j++) cin >> arr[i][j];
        for (int a = 0; a < 5; a++) {
            for (int b = a + 1; b < 5; b++) arr[i][j++] = arr[i][a] & arr[i][b];
        }
    }
    vector<int> cumm(15, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 15; j++) cumm[j] += arr[i][j];
    }
    int j = 5;
    for (int a = 0; a < 5; a++) {
        for (int b = a + 1; b < 5; b++) {

            if (cumm[a] + cumm[b] - cumm[j] == n) {
                if (cumm[a] - cumm[j] <= n / 2 && cumm[b] - cumm[j] <= n / 2) return true;
            }
            j++;
        }
    }
    return false;
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

        if (solve()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}