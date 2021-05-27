#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(const vector<int> &A, int B) {
        
        int n = A.size();
        unordered_map<int, pair<int, int>> map;
        for (int i = 0; i < n; i++) {
            if (map.find(A[i]) == map.end()) {
                map[A[i]].first = i;
                map[A[i]].second = -1;
            }
            else if (map[A[i]].second == -1) map[A[i]].second = i;
        }
        vector<int> res = {n, n};
        int l, r;
        for (int i = 0; i < n; i++) {
            
            if (map.find(B - A[i]) == map.end()) continue;
            if (map[B - A[i]].first != i) {
                l = min(i, map[B - A[i]].first);
                r = max(i, map[B - A[i]].first);
            }
            else if (map[B - A[i]].second == -1) continue;
            else {
                l = i;
                r = map[B - A[i]].second;
            }
            if (r < res[1] || (r == res[1] && l < res[0])) {
                res[0] = l;
                res[1] = r;
            }
        }
        if (res[0] == n) return {};
        res[0]++;
        res[1]++;
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    for (int e: obj.twoSum(arr, k)) cout << e << " ";
}