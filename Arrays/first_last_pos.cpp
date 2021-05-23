#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(vector<int>& arr, int k) {

        vector<int> range = {-1, -1};
        int l = 0, r = arr.size() - 1;
        
        while (l <= r) {
            int mid = (l + r) / 2;
            
            if (arr[mid] < k) {
                l = mid + 1;
                continue;
            }
            if (arr[mid] == k) range[0] = mid;
            r = mid - 1;
        }
        l = range[0], r = arr.size() - 1;
        
        while (l <= r) {
            int mid = (l + r) / 2;
            
            if (arr[mid] > k) {
                r = mid - 1;
                continue;
            }
            if (arr[mid] == k) range[1] = mid;
            l = mid + 1;
        }
        return range;
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
    for (int e: obj.solve(arr, k)) cout << e << " ";
}