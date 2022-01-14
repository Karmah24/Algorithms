#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> combos;

    void getCombos(int i, int x, vector<int>& arr, vector<int>& combo) {

        if (x <= 0) {
            if (x == 0) combos.push_back(combo);
            return;
        }
        for (int j = i; j < arr.size(); j++) {
            combo.push_back(arr[j]);
            getCombos(j, x - arr[j], arr, combo);
            combo.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& arr, int x) {
        sort(arr.begin(), arr.end());
        auto it = unique(arr.begin(), arr.end());
        arr.resize(it - arr.begin());
        combos.clear();
        vector<int> combo;
        getCombos(0, x, arr, combo);
        return combos;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, x;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> x;
    Solution obj;
    for (auto v: obj.combinationSum(arr, x)) {
        for (int e: v) cout << e << " ";
        cout << endl;
    }
}