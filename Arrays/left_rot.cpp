#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for (int i = 0; i < n; i++)
const int N = 3e5, M = N;
//=======================
int arr[N];

void solve(int n, int k) {
    int x, y;
    loop (i, n) cin >> arr[i];
    k = k % n;
    x = 0, y = k - 1;
    while (x < y) {
        swap(arr[x], arr[y]);
        x++;
        y--;
    }
    x = k, y = n - 1;
    while (x < y) {
        swap(arr[x], arr[y]);
        x++;
        y--;
    }
    x = 0, y = n - 1;
    while (x < y) {
        swap(arr[x], arr[y]);
        x++;
        y--;
    }
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        solve(n, k);
        loop (i, n)
            cout << arr[i] << " ";
        cout << endl;      
    }
    return 0;
}