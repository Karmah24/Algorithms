#include <bits/stdc++.h>
using namespace std;

class Solution {
    pair<int, int> maxMin(vector<int>& arr, int l, int r) {

    if (l == r) return {arr[l], arr[l]};
    if (r - l == 1) {
        if (arr[l] < arr[r]) return {arr[l], arr[r]};
        else return {arr[r], arr[l]};
    }
    int mid = (l + r) / 2;
    auto lo = maxMin(arr, l, mid);
    auto hi = maxMin(arr, mid + 1, r);

    return {min(lo.first, hi.first), max(lo.second, hi.second)};
}
public:
   int solve(vector<int>& arr) {
        auto res = maxMin(arr, 0, arr.size() - 1);
        return res.first + res.second;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    cout << obj.solve(arr);
}