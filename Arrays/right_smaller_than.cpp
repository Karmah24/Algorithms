#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val, leftSubSize = 1;
    TreeNode *left = nullptr, *right = nullptr;
    TreeNode(int x) : val(x) {}
};

class Tree {
    TreeNode* root = nullptr;
public:
    int insert(int val, TreeNode* curr = nullptr, int prevLeft = 0) {
        if (!curr) curr = root;
        TreeNode* t = new TreeNode(val);
        if (!root) {
            root = t;
            return 0;
        }
        if (val <= curr->val) {
            curr->leftSubSize++;
            if (!curr->left) {
                curr->left = t;
                return prevLeft;
            }
            return insert(val, curr->left, prevLeft);
        }
        if (!curr->right) {
            curr->right = t;
            return prevLeft + curr->leftSubSize;
        }
        return insert(val, curr->right, prevLeft + curr->leftSubSize);
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        Tree tree;
        for (int i = nums.size() - 1; i >= 0; i--) res[i] = tree.insert(nums[i]);
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    Solution obj;
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        for (int e: obj.countSmaller(nums)) cout << e << ' ';
        cout << endl;
    }
}
