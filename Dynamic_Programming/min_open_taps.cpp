#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        vector<int> reach(n + 1, 0);
        
        for (int i = 0; i <= n; i++) {
            
            int lo = max(0, i - ranges[i]);
            int hi = min(n, i + ranges[i]);
            reach[lo] = max(reach[lo], hi);
        }
        if (reach[0] == 0) return -1;
        int steps = reach[0], maxReach = reach[0], taps = 1;
        for (int i = 1; i < n; i++) {
            
            maxReach = max(maxReach, reach[i]);
            if (--steps == 0) {
                taps++;
                steps = maxReach - i;
                if (steps == 0) return -1;
            }
        }
        return taps;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 0; i <= n; i++) cin >> arr[i];
    Solution obj;
    cout << obj.minTaps(n, arr);
}