// Lower Envolope of Monotonic functions
#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for (int i = 0; i < n; i++)
const int N = 1e7, M = N;
//=======================
int arr[N];

int solve() {
    int n, c = 0, l, r, i, j;
    cin >> n;
    loop (i, n) cin >> arr[i];

    i = 0, j = n - 1;
    l = arr[0], r = arr[n - 1];
    while (i < j) {
        l = max(l, arr[i]);
        r = max(r, arr[j]);
        if (l < r) {
            c += l - arr[i];
            i++;
        }
        else {
            c += r - arr[j];
            j--;
        }
    }
    return c;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cout << solve() << endl;
    }
    return 0;
}
