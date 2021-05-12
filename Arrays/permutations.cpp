#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void get_perms(int i, vector<int>& nums, vector<vector<int>>& perms) {
        if (i == nums.size() - 1) perms.push_back(nums);
        
        else {
            for (int j = i; j < nums.size(); j++) {
                swap(nums[i], nums[j]);
                get_perms(i + 1, nums, perms);
                swap(nums[i], nums[j]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        get_perms(0, nums, res);
        return res;
    }
};