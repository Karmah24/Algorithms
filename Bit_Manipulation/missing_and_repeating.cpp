#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    vector<int> find_unique(vector<int>& nums) {
    
        int xxory = nums[0];
        for (int i = 1 ; i < nums.size(); i++) {
            xxory ^= nums[i];
        }
        int mask = (xxory & (xxory - 1)) ^ xxory;
        int x = 0, y = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & mask) x ^= nums[i];
            else y ^= nums[i];
        }
        return {x, y};
    }
public:
    vector<int> solve(vector<int>& nums, int n) {
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        return find_unique(nums);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    for (int e: obj.solve(nums, n)) cout << e << ' ';
}
