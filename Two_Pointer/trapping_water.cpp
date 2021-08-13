// Lower Envolope of Monotonic functions

#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n) {

    int i = 1, j = n - 2, l = arr[0], r = arr[n - 1];
    int res = 0;

    while (i <= j) {

        l = max(l, arr[i]);
        r = max(r, arr[j]);

        if (l < r) {
            res += l - arr[i];
            i++;
        }
        else {
            res += r - arr[j];
            j--;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << solve(arr, n) << endl;
}
