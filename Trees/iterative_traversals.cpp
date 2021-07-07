#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> preorderTraversal(TreeNode* root) {
    
    vector<int> res;
    if (!root) return res;
    
    stack<TreeNode*> st;
    st.push(root);
    
    while (!st.empty()) {
        TreeNode *u = st.top();
        st.pop();
        res.push_back(u->val);
        if (u->right) st.push(u->right);
        if (u->left) st.push(u->left);
    }
    return res;
}
 
vector<int> inorderTraversal(TreeNode* root) {
    
    vector<int> res;
    if (!root) return res;
    
    stack<TreeNode*> st;
    st.push(root);
    unordered_set<TreeNode*> vis;
    
    while (!st.empty()) {
        TreeNode *u = st.top();
        if (u->left && !vis.count(u->left)) {
            vis.insert(u->left);
            st.push(u->left);
        }
        else {
            st.pop();
            res.push_back(u->val);
            if (u->right) st.push(u->right);
        }
    }
    return res;
}

vector<int> postorderTraversal(TreeNode* root) {
    
    vector<int> res;
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    
    st1.push(root);
    
    while (!st1.empty()) {
        
        TreeNode *u = st1.top();
        st1.pop();
        st2.push(u);
        if (u->left) st1.push(u->left);
        if (u->right) st1.push(u->right);
    }
    while (!st2.empty()) {
        res.push_back(st2.top()->val);
        st2.pop();
    }
    return res;
}