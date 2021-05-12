#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
//=======================

class Solution {
public:
    int getMinDiff(int arr[], int n, int k) {

        vector<pair<int, int>> heights;
        for (int i = 0; i < n; i++) {

            if (arr[i] >= k) heights.push_back({arr[i] - k, i});
            heights.push_back({arr[i] + k, i});
        }
        sort(heights.begin(), heights.end());

        unordered_map<int, int> map;
        int towers = 0, res = INT_MAX;

        int lo = 0, hi = 0;
        while (lo <= hi && hi < heights.size()) {

            if (towers == n) {  
                res = min(res, heights[hi].first - heights[lo].first);
                if (map[heights[lo].second]-- == 1) {
                    towers--;
                    hi++;
                }
                lo++;
            }
            else {
                int h = heights[hi].first, idx = heights[hi].second;
                if (map[idx]++ == 0) towers++;
                
                if (towers < n) hi++;
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, k;
    cin >> k >> n;
    int arr[n];
    loop (i, n) cin >> arr[i];
    Solution obj;
    cout << obj.getMinDiff(arr, n, k);
}
