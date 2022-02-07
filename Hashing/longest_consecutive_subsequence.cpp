// You have been given an array A of a positive integer.
// Your task is to calculate the length of the longest possible subsequence of array A such that the absolute difference of any two numbers of subsequences is not more than 2.
// Note:- A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements

#include <bits/stdc++.h>
using namespace std;
// #define int long long
//=======================

int solve() {
    
    int n, res = 1;
    cin >> n;
    vector<int> arr(n);
    unordered_map<int, int> cnt;
    for (auto &e: arr) {
        cin >> e;
        cnt[e]++;
    }
    for (auto &[k, v]: cnt) {
        res = max(res, v + cnt[k - 1] + cnt[k - 2]);
        res = max(res, v + cnt[k - 1] + cnt[k + 1]);
        res = max(res, v + cnt[k + 1] + cnt[k + 2]);
    }
    return res;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}