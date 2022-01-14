#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &arr) {

    int oddPre = 0, evenPre = 0, oddSuf = 0, evenSuf = 0;
    for (int i = 0; i < n; i++) {
        if (i & 1) evenSuf += arr[i];
        else oddSuf += arr[i];
    }
    int res = 0;
    for (int i = 0; i < n; i++) {

        if (i & 1) evenSuf -= arr[i];
        else oddSuf -= arr[i];
        if (evenPre + oddSuf == oddPre + evenSuf) res++;
        if (i & 1) evenPre += arr[i];
        else oddPre += arr[i];
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << solve(n, arr);
}