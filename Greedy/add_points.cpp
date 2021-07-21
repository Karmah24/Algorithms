#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int solve(int n, int arr[]) {

    sort(arr, arr + n);
    ll gap = arr[1] - arr[0];

    for (int i = 2; i < n; i++) {
        gap = gcd(gap, arr[i] - arr[i - 1]);
    }
    return ((ll)(arr[n - 1] - arr[0]) / gap) - n + 1;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << solve(n, arr);
}