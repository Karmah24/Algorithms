#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
typedef vector<int>		vi;
//=======================

class Solution {
public:
    // int jump(vector<int>& nums) {
    //     int n = nums.size();
    //     vi res(n);
    //     fori (i, n) res[i] = INT_MAX;
    //     res[n - 1] = 0;
    //     for (int i = n - 2; i >= 0; i--) {
    //         if (n - i - 1 <= nums[i]) res[i] = 1;
    //         else {
    //             for (int j = i + 1; j <= i + nums[i]; j++) {
    //                 if (res[j] != INT_MAX)
    //                     res[i] = min(res[i], res[j] + 1);
    //             }
    //         }
    //     }
    //     return res[0];
    // }
    int jump(vector<int>& nums) {

        if (nums.size() == 1) return 0;
        if (nums[0] == 0) return -1;
        
        int max_reach = nums[0], steps = nums[0], jumps = 1;

        for (int i = 1; i < nums.size() - 1; i++) {
            max_reach = max(max_reach, i + nums[i]);
            steps--;
            if (steps == 0) {
                jumps++;
                steps = max_reach - i;
                if (steps == 0 && nums[i] == 0) return -1;
            }
        }
        return jumps;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int T = 1;
    // cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi nums(n);
        loop (i, n) cin >> nums[i];
        Solution obj;
        cout << obj.jump(nums) << endl;
    }
}
