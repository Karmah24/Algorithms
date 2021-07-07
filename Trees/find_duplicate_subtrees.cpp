#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left = nullptr, *right = nullptr;
    Node(int x) : data(x) {}
};

string dfs(Node *u, unordered_map<string, int> &mp, vector<Node*> &res) {

    if (!u) return "";
    string l = dfs(u->left, mp, res);
    string r = dfs(u->right, mp, res);
    string s = "(" + l + to_string(u->data) + r + ")";

    if (++mp[s] == 2) res.push_back(u);
    return s;
}
vector<Node*> findDuplicates(Node *root) {

    unordered_map<string, int> mp;
    vector<Node*> res;
    dfs(root, mp, res);
    return res;
}