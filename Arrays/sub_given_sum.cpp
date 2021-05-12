#include<bits/stdc++.h>
using namespace std;

#define fori(i, n) for (int i = 0; i < n; i++)
//=======================

void solve(vector<int>& arr, int s) {
    int sum, x = 0, y = 0, n = arr.size();
    sum = arr[0];
    while (1) {
        while (y < n - 1 && sum < s) sum += arr[++y];

        if (y == n - 1 && sum < s) {  // sum of all less than s
            cout << -1 << endl;
            break;
        }
        if (s == sum) {
           cout << x + 1 << " " << y + 1 << endl;
           break;
        }
        while (x < y && sum > s) sum -= arr[x++];

        if (x == y && sum > s) {
            if (x == n - 1) {  // smallest element greater than s
                cout << -1 << endl;
                break;
            }
            sum = arr[++x];
            y++;
        }
        if (s == sum) {
           cout << x + 1 << " " << y + 1 << endl;
           break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        int n, s;
        cin >> n >> s;
        vector<int> arr(n);
        fori (i, n) cin >> arr[i];
        solve(arr, s);
    }
    return 0;
}