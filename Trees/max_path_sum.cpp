#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, -1001};

        pair<int, int> mps_left = dfs(root->left);
        pair<int, int> mps_right = dfs(root->right);

        int branch_max =  max(max(mps_left.first, mps_right.first), 0) + root->val;
        int temp = max(root->val, mps_left.first + root->val);
        int if_in = max(temp, temp + mps_right.first);
        int if_out = max(mps_left.second, mps_right.second);
        int sub_max = max(if_in, if_out);
        
        return {branch_max, sub_max};
    }
    int maxPathSum(TreeNode* root) {
        pair<int, int> mps = dfs(root);
        return max(mps.first, mps.second);
    }
};