#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left = nullptr, *right = nullptr;
    Node(int x) : data(x) {}
};

bool res;

int dfs(Node *u) {

    if (!u || !res) return 0;
    int l = dfs(u->left);
    int r = dfs(u->right);
    if (abs(r - l) > 1) res = false;
    return max(l, r) + 1;
}
bool isBalanced(Node *root) {
    res = true;
    int ht = dfs(root);
    return res;
}