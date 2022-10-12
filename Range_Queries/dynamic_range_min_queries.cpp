#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
const int N = (1 << 20) - 1; // array size upto 5e5
//=======================

int sgt[N];

int build(int idx, int l, int r, int arr[]) {

    if (l == r) return sgt[idx] = arr[l];

    int mid = (l + r) / 2;
    int left = build(idx * 2 + 1, l, mid, arr);
    int right = build(idx * 2 + 2, mid + 1, r, arr);

    return sgt[idx] = min(left, right);
}
int getMin(int idx, int sl, int sr, int ql, int qr) {

    if (ql <= sl && sr <= qr) return sgt[idx];
    if (sr < ql || qr < sl) return INT_MAX;

    int mid = (sl + sr) / 2;
    int left = getMin(idx * 2 + 1, sl, mid, ql, qr);
    int right = getMin(idx * 2 + 2, mid + 1, sr, ql, qr);

    return min(left, right);
}
void update(int idx, int sl, int sr, int k, int u) {

    if (sl == sr) {
        sgt[idx] = u;
        return;
    }
    int mid = (sl + sr) / 2;
    if (k <= mid) update(idx * 2 + 1, sl, mid, k, u);
    else update(idx * 2 + 2, mid + 1, sr, k, u);
    
    sgt[idx] = min(sgt[idx * 2 + 1], sgt[idx * 2 + 2]);
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

        if (a == 1) update(0, 0, n - 1, b - 1, c);
        else cout << getMin(0, 0, n - 1, b - 1, c - 1) << ln;
    }
    return 0;
}