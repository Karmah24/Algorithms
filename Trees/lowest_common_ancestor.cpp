#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int P, Q;
TreeNode *p, *q;

TreeNode* insert(TreeNode* root, int val){
    if(!root) {
        if (val == P) return p = new TreeNode(val);
        if (val == Q) return q = new TreeNode(val);
        return new TreeNode(val);
    }
    
    if(root->val > val)
        root->left = insert(root->left, val);
    else if(root->val < val)
        root->right = insert(root->right, val);
    return root;
}
void traverse(TreeNode* root){
    if (root) {
        traverse(root->left);
        cout << root->val << ' ';
        traverse(root->right);
    }
}

class Solution {
    TreeNode* lca = NULL;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (lca) return true;
        if (!root) return false;
        
        bool left = dfs(root->left, p, q);
        bool right = dfs(root->right, p, q);
        bool mid = (root == p || root == q);

        if (left && right || mid && (left || right)) {
            if (!lca) lca = root;
        }
        if (left || right || mid) return true;
        
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return lca;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
    int N;
    cin >> P >> Q >> N;
    TreeNode* root = NULL;
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        root = insert(root, k);
    }
    cout << root->right->val;
    Solution obj;
    cout << endl << obj.lowestCommonAncestor(root, p, q)->val;
}