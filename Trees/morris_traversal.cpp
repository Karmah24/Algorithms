#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left = nullptr, *right = nullptr;
    Node(int x) : data(x) {}
};

Node* right_most(Node *lSub, Node *u) {

    while (lSub->right && lSub->right != u) lSub = lSub->right;
    return lSub;
}

vector<int> inOrder(Node *root) {

    vector<int> res;
    Node *u = root;

    while (u) {

        if (!u->left) {
            res.push_back(u->data);
            u = u->right;
        }
        else {
            Node *r = right_most(u->left, u);
            if (r->right != u) {
                r->right = u;
                u = u->left;
            }
            else {
                res.push_back(u->data);
                r->right = nullptr;
                u = u->right;
            }
        }
    }
    return res;
}