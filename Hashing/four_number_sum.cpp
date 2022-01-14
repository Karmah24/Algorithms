#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& A, int B) {

        int n = A.size();
        map<int, set<pair<int, int>>> mp;
        set<vector<int>> res;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = A[i] + A[j], t = B - sum;
                if (mp.find(t) == mp.end()) continue;
                for (auto p: mp[t]) {
                    vector<int> v = {p.first, p.second, A[i], A[j]};
                    sort(v.begin(), v.end());
                    res.insert(v);
                }
            }
            for (int j = 0; j < i; j++) {
                int sum = A[i] + A[j];
                mp[sum].insert({A[j], A[i]});
            }
        }
        vector<vector<int>> ans;
        for (auto v: res) ans.push_back(v);
        return ans;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    for (auto e: obj.fourSum(arr, k)) {
        for (int x: e) cout << x << ' ';
        cout << endl;
    }
}
