#include <bits/stdc++.h>
using namespace std;

#define ln '\n'

struct range {
    int l, r, idx;

    bool operator < (const range &other) {
        if (l == other.l) return r > other.r;
        return l < other.l;
    }
};
void solve() {

    int n;
    cin >> n;
    
    range arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i].l >> arr[i].r;
        arr[i].idx = i;
    }
    sort(arr, arr + n);
    bool contains[n], contained[n];
    
    contains[arr[n - 1].idx] = false;
    int minR = arr[n - 1].r;
    for (int i = n - 2; i >= 0; i--) {

        if (arr[i].r >= minR) contains[arr[i].idx] = true;
        else {
            minR = arr[i].r;
            contains[arr[i].idx] = false;
        }
    }
    contained[arr[0].idx] = false;
    int maxR = arr[0].r;
    for (int i = 1; i < n; i++) {

        if (arr[i].r <= maxR) contained[arr[i].idx] = true;
        else {
            maxR = arr[i].r;
            contained[arr[i].idx] = false;
        }
    }
    for (bool b: contains) cout << b << " ";
    cout << ln;
    for (bool b: contained) cout << b << " ";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}