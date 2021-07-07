#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left = nullptr, *right = nullptr;
    Node (int x) : data(x) {}
};

void printLevelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);
    string s;
    while (!q.empty()) {
        Node *t = q.front();
        q.pop();
        s.append(t == nullptr ? "N" : to_string(t->data)).append(" ");
        if (t && (t->left || t->right)) {
            q.push(t->left);
            q.push(t->right);
        }
    }
    s.pop_back();
    cout << s << endl;
}

int p;
unordered_map<int, int> mp;

Node* build(vector<int> &pre, vector<int> &in, int l, int r) {

    if (l > r) return nullptr;

    int root_pos = mp[pre[p]];
    Node *root = new Node(pre[p++]);

    root->left = build(pre, in, l, root_pos - 1);
    root->right = build(pre, in, root_pos + 1, r);

    return root;
}
Node* buildTree(vector<int> &preorder, vector<int> &inorder) {

    p = 0;
    mp.clear();
    for (int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;

    return build(preorder, inorder, 0, inorder.size() - 1);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; i++) cin >> v1[i];
    for (int i = 0; i < n; i++) cin >> v2[i];
    printLevelOrder(buildTree(v1, v2));
}