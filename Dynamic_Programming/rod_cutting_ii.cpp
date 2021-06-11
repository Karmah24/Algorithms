#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
    vector<vector<ll>> dp;
    vector<vector<int>> cut_pos;

    ll solve(vector<int>& arr, int l, int r) {

        if (r - l < 2) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        ll res = LLONG_MAX, idx = -1;
        for (int i = l + 1; i < r; i++) {

            ll curr = arr[r] - arr[l] + solve(arr, l, i) + solve(arr, i, r);
            if (curr < res) {
                res = curr;
                idx = i;
            }
        }
        cut_pos[l][r] = idx;
        return dp[l][r] = res;
    }

    void getSeq(vector<int>& arr, int l, int r, vector<int>& res) {

        if (r - l < 2) return;

        int cut = cut_pos[l][r];
        res.push_back(arr[cut]);
        getSeq(arr, l, cut, res);
        getSeq(arr,cut, r, res);
    }
public:
    vector<int> rodCut(int n, vector<int>& A) {

        sort(A.begin(), A.end());
        vector<int> arr = {0};
        arr.insert(arr.end(), A.begin(), A.end());
        arr.push_back(n);

        dp = vector<vector<ll>>(arr.size(), vector<ll>(arr.size(), -1));
        cut_pos = vector<vector<int>>(arr.size(), vector<int>(arr.size(), -1));
        solve(arr, 0, arr.size() - 1);

        vector<int> res;
        getSeq(arr, 0, arr.size() - 1, res);
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<int> arr(k);
    for (int i = 0; i < k; i++) cin >> arr[i];
    Solution obj;
    for (int e: obj.rodCut(n, arr)) cout << e << " ";
}