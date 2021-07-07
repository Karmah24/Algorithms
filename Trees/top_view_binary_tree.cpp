#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left = nullptr, *right = nullptr;
    Node(int x) : data(x) {}
};

vector<int> topView(Node *root) {

    unordered_map<int, int> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    mp[0] = root->data;
    int minLvl = 0, maxLvl = 0;

    while (!q.empty()) {

        Node *u = q.front().first;
        int lvl = q.front().second;
        q.pop();
        minLvl = min(minLvl, lvl);
        maxLvl = max(maxLvl, lvl);

        if (mp.count(lvl) == 0) mp[lvl] = u->data;
        if (u->left) q.push({u->left, lvl - 1});
        if (u->right) q.push({u->right, lvl + 1});
    }
    vector<int> res(maxLvl - minLvl + 1);
    for (auto p: mp) {
        res[p.first - minLvl] = p.second;
    }
    return res;
}