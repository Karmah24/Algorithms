#include<bits/stdc++.h>
using namespace std;

class SGT {
public:

    int n;
    vector<int> sgt;
    SGT(int n) {
        this-> n = n;
        sgt.assign(4 * n, 0);
    }
    void update(int k, int i, int sl = 0, int sr = -1, int idx = 0) {
        if (sr == -1) sr = n - 1;
        if (sl == sr) {
            sgt[idx] = k;
            return;
        }
        int mid = (sl + sr) / 2;
        if (i <= mid) update(k, i, sl, mid, idx * 2 + 1);
        else update(k, i, mid + 1, sr, idx * 2 + 2);
        sgt[idx] = max(sgt[idx * 2 + 1], sgt[idx * 2 + 2]);
    }
    int query(int ql, int qr, int sl = 0, int sr = -1, int idx = 0) {
        if (sr == -1) sr = n - 1;
        if (ql <= sl && sr <= qr) return sgt[idx];
        if (qr < sl || sr < ql) return 0;
        int mid = (sl + sr) / 2;
        int left = query(ql, qr, sl, mid, idx * 2 + 1);
        int right = query(ql, qr, mid + 1, sr, idx * 2 + 2);
        return max(left, right);
    }
};

int lis_sgt(vector<int>& a) {

    int n = a.size();
    for (int i = 0; i < n; i++) a[i] += 10001;
    vector<int> dp(n);
    SGT sgt(20005);
    for (int i = 0; i < n; i++) {
        dp[i] = sgt.query(0, a[i] - 1) + 1;
        sgt.update(dp[i], a[i]);
    }
    int res = 0;
    for (int i = 0; i < n; i++) res = max(res, dp[i]);
    return res;
}

int lis_dp(vector<int> &arr) {

    int n = arr.size();
    vector<int> dp(n, 1);
    int res = 1;
    for (int i = 1; i < n ; i++) {
        for (int j = 0; j < i; j++) {

            if (arr[i] > arr[j] && dp[i] <= dp[j]) {
                dp[i] = dp[j] + 1;
                res = max(res, dp[i]);
            }
        }
    }
    return res;
}
int lis_bin_search(vector<int>& arr) {

    vector<int> lis;
    for (auto &e: arr)  {
        auto lb = lower_bound(lis.begin(), lis.end(), e);
        if (lb == lis.end()) lis.push_back(e);
        else *lb = e;
    }
    return lis.size();
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << lis_bin_search(arr);
}