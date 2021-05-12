#include<bits/stdc++.h>

using namespace std;

#define fori(i, n) for (int i = 0; i < n; i++)

const int mod = int(1e9 + 7);
const int N = 3e5, M = N;
//=======================

int arr[N];

int solve() {
    int n, i, j, k, c = 0;
    cin >> n;
    fori (x, n) cin >> arr[x];
    sort(arr, arr + n);
    i = n - 1;
    while (i >= 2) {
        j = i - 1;
        k = 0;
        while (j > k) {
            if (arr[j] + arr[k] < arr[i])
                k++;
            else if (arr[j] + arr[k] > arr[i])
                j--;
            else {
                c++;
                k++;
                j--;
            }
        }
        i--;
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