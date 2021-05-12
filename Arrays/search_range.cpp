    #include <bits/stdc++.h>
    using namespace std;

    #define loop(i, n) for (int i = 0; i < n; i++)
    typedef vector<int>		vi;
    //=======================

    class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            // vector<int>::iterator lower, upper;
            // lower = lower_bound(nums.begin(), nums.end(), target);
            // upper = upper_bound(nums.begin(), nums.end(), target);
            // int low = lower - nums.begin();
            // int up = upper - nums.begin();
            // if (up > low)
            //     return {low, up - 1};
            // return {-1, -1};

            int l = 0, r = nums.size() - 1;
            int lower = -1, upper = -1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (nums[mid] == target && (mid == 0 || nums[mid - 1] != target)) {
                    lower = mid;
                    break;
                }
                else if (nums[mid] >= target) r = mid - 1;
                else l = mid + 1;
            }
            l = 0, r = nums.size() - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (nums[mid] == target && (mid == nums.size() - 1 || nums[mid + 1] != target)) {
                    upper = mid;
                    break;
                }
                else if (nums[mid] <= target) l = mid + 1;
                else r = mid - 1;
            }
            return {lower, upper};
        }
    };
    int main() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        int T = 1;
        cin >> T;
        while (T--) {
            int n, k;
            cin >> n >> k;
            vi nums(n);
            loop (i, n) cin >> nums[i];
            Solution obj;
            for (int e: obj.searchRange(nums, k)) cout << e << ' ';
            cout << endl;
        }
    }
