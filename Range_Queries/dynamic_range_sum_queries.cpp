#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
const int N = (1 << 19) - 1;
//=======================

ll sgt[N];

ll build(int idx, int lo, int hi, int arr[]) {

    if (lo == hi) return sgt[idx] = arr[lo];

    int mid = (lo + hi) / 2;
    ll left = build(idx * 2 + 1, lo, mid, arr);
    ll right = build(idx * 2 + 2, mid + 1, hi, arr);

    return sgt[idx] = left + right;
}
ll getSum(int idx, int sl, int sh, int lo, int hi) {

    if (lo <= sl && sh <= hi) return sgt[idx];
    if (sh < lo || hi < sl) return 0;

    int mid = (sl + sh) / 2;
    ll left = getSum(idx * 2 + 1, sl, mid, lo, hi);
    ll right = getSum(idx * 2 + 2, mid + 1, sh, lo, hi);

    return left + right;
}
// void update(int idx, int sl, int sh, int k, int u) {
    
//     sgt[idx] += u;
//     if (sl == sh) return;

//     int mid = (sl + sh) / 2;
//     if (k <= mid) update(idx * 2 + 1, sl, mid, k, u);
//     else update(idx * 2 + 2, mid + 1, sh, k, u);
// }
void update(int idx, int sl, int sh, int k, int u) {
    if (sl == sh) {
        sgt[idx] = u;
        return;
    }
    int mid = (sl + sh) / 2;
    if (k <= mid) update(idx * 2 + 1, sl, mid, k, u);
    else update(idx * 2 + 2, mid + 1, sh, k, u);
    sgt[idx] = sgt[idx * 2 + 1] + sgt[idx * 2 + 2];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    build(0, 0, n - 1, arr);

    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;

        // if (a == 1) {
        //     if (arr[b - 1] != c) update(0, 0, n - 1, b - 1, c - arr[b - 1]);
        //     arr[b - 1] = c;
        // }
        if (a == 1) update(0, 0, n - 1, b - 1, c);
        else cout << getSum(0, 0, n - 1, b - 1, c - 1) << ln;
    }
    return 0;
}