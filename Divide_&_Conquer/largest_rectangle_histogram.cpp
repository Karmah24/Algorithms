#include <bits/stdc++.h>
using namespace std;

#define ll long long
//=======================

class Solution {

    vector<pair<ll, int>> sgt;

    int size(int n) {
        if (!(n & (n - 1))) return (n << 1) - 1;

        int count = 0;
        while (n) {
            count++;
            n = n >> 1;
        }
        return (1 << (count + 1)) - 1;
    }

    pair<ll, int> constructST(int si, ll arr[], int lo, int hi) {
        if (lo == hi) {
            sgt[si].first = arr[lo];
            sgt[si].second = lo;
            return sgt[si];
        }

        int mid = (lo + hi) / 2;
        auto left = constructST(si * 2 + 1, arr, lo, mid);
        auto right = constructST(si * 2 + 2, arr, mid + 1, hi);
        
        sgt[si] = left.first <= right.first ? left : right;

        return sgt[si];
    }

    pair<ll, int> getMin(int si, int sl, int sh, int lo, int hi) {
        // total overlap
        if (lo <= sl && sh <= hi) return sgt[si];
        // no overlap
        if (sh < lo || hi < sl) return {LLONG_MAX, -1};
        // partial overlap
        int mid = (sl + sh) / 2;
        auto left = getMin(si * 2 + 1, sl, mid, lo, hi);
        auto right = getMin(si * 2 + 2, mid + 1, sh, lo, hi);

        return left.first <= right.first ? left : right;
    }

    ll getMaxAreaUtil(int lo, int hi, int n) {

        if (lo < 0 || hi >= n || lo > hi) return LLONG_MIN;

        auto p = getMin(0, 0, n - 1, lo, hi);
        ll res = p.first * (hi - lo + 1);
        if (p.second == -1) return res;
        ll left = getMaxAreaUtil(lo, p.second - 1, n);
        ll right = getMaxAreaUtil(p.second + 1, hi, n);

        return max({res, left, right});
    }
public:
    ll getMaxArea(ll arr[], int n) {

        int N = size(n);
        sgt.resize(N);
        constructST(0, arr, 0, n - 1);
        return getMaxAreaUtil(0, n - 1, n);
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++) arr[i];
    Solution obj;
    cout << obj.getMaxArea(arr, n);
}
