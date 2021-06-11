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
    pair<int, int> solve(TreeNode* root) {
        if (!root) return {0, -1001};

        pair<int, int> l = solve(root->left);
        pair<int, int> r = solve(root->right);

        int branch_max =  max({l.first, r.first, 0}) + root->val;

        int temp = max(root->val, l.first + root->val);
        int if_in = max(temp, temp + r.first);
        int if_out = max(l.second, r.second);
        int sub_max = max(if_in, if_out);
        
        return {branch_max, sub_max};
    }
    int maxPathSum(TreeNode* root) {
        pair<int, int> mps = solve(root);
        return max(mps.first, mps.second);
    }
};