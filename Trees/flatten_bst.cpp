#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int parseInt(string s) {
    stringstream ss(s);
    int num;
    ss >> num;
    return num;
}

TreeNode* buildTree() {
    vector<string> in;
    string s;
    while (getline(cin, s, ',')) in.push_back(s);

    if (in[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(parseInt(in[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < in.size()) {
        TreeNode* t = q.front();
        q.pop();
        if (t == nullptr) continue;

        t->left = in[i] == "null" ? nullptr : new TreeNode(parseInt(in[i]));
        q.push(t->left);
        i++;
        if (i == in.size()) break;
        t->right = in[i] == "null" ? nullptr : new TreeNode(parseInt(in[i]));
        q.push(t->right);
        i++;
    }
    return root;
}

void printLevelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    string s;
    while (!q.empty()) {
        TreeNode* t = q.front();
        q.pop();
        s.append(t == nullptr ? "null" : to_string(t->val)).append(",");
        if (t && (t->left || t->right)) {
            q.push(t->left);
            q.push(t->right);
        }
    }
    s.pop_back();
    cout << s << endl;
}

class Solution {
    pair<TreeNode*, TreeNode*> solve(TreeNode *root) {
    
        if (!root->left && !root->right) return {root, root};
        
        pair<TreeNode*, TreeNode*> llist, rlist;
        if (!root->right) {
            llist = solve(root->left);
            root->left = nullptr;
            root->right = llist.first;
            return {root, llist.second};
        }
        if (!root->left) {
            rlist = solve(root->right);;
            root->right = rlist.first;
            return {root, rlist.second};
        }
        TreeNode *r = root->right;
        llist = solve(root->left);
        root->left = nullptr;
        root->right = llist.first;
        rlist = solve(r);
        llist.second->right = rlist.first;
        
        return {root, rlist.second};
    }
public:
    TreeNode* flatten(TreeNode* A) {   
        return solve(A).first;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    TreeNode* root = buildTree();
    Solution obj;
    TreeNode* head = obj.flatten(root);
    printLevelOrder(head);
}