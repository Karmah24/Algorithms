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
void update(int idx, int sl, int sh, int k, int u) {

    sgt[idx] += u;
    if (sl == sh) return;
    int mid = (sl + sh) / 2;
    if (k <= mid) update(idx * 2 + 1, sl, mid, k, u);
    else update(idx * 2 + 2, mid + 1, sh, k, u);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int diff[n];
    diff[0] = arr[0];
    for (int i = 1; i < n; i++) diff[i] = arr[i] - arr[i - 1];

    build(0, 0, n - 1, diff);
    
    while (q--) {
        int qType;
        cin >> qType;
        if (qType == 1) {
            int l, r, u;
            cin >> l >> r >> u;
            update(0, 0, n - 1, l - 1, u);
            if (r < n) update(0, 0, n - 1, r, -u);
        }
        else {
            int p;
            cin >> p;
            cout << getSum(0, 0, n - 1, 0, p - 1) << ln;
        }
    }
    return 0;
}