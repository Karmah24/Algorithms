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
    pair<TreeNode*, TreeNode*> solve(TreeNode* curr, TreeNode* par) {
        if (!curr) return {par, par};
        auto [leftMost, prev] = solve(curr->left, curr);
        auto [next, rightMost] = solve(curr->right, curr);
        
        prev->left = nullptr;
        if (prev != curr) prev->right = curr;
        curr->left = nullptr;
        if (curr != next) curr->right = next;
        return {leftMost, rightMost};
    }
public:
    TreeNode* flatten(TreeNode* root) {
        if (!root ||(!root->left && !root->right)) return root;
        TreeNode *next;
        auto [head, prev] = solve(root->left, root);
        next = solve(root->right, root).first;

        prev->left = nullptr; prev->right = root;
        root->left = nullptr; root->right = next;
        return head;
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
