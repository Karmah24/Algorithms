#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void get_perms(int i, vector<int>& arr, set<vector<int>>& perms) {
        
        if (i == arr.size() - 1) {
            perms.insert(arr);
            return;
        }
        for (int j = i; j < arr.size(); j++) {
            swap(arr[i], arr[j]);
            get_perms(i + 1, arr, perms);
            swap(arr[i], arr[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& arr) {
        set<vector<int>> perms;
        get_perms(0, arr, perms);
        vector<vector<int>> res;
        for (auto v: perms) res.push_back(v);
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    for (auto v: obj.permute(arr)) {
        for (int e: v) cout << e << " ";
        cout << endl;
    }
}