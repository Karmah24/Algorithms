#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

int parseInt(string s) {
    stringstream ss(s);
    int num;
    ss >> num;
    return num;
}

Node* buildTree() {
    vector<string> in;
    string s;
    while (getline(cin, s, ' ')) in.push_back(s);

    if (in[0] == "null") return nullptr;

    Node* root = new Node(parseInt(in[0]));
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < in.size()) {
        Node* t = q.front();
        q.pop();
        if (t == nullptr) continue;

        t->left = in[i] == "null" ? nullptr : new Node(parseInt(in[i]));
        q.push(t->left);
        i++;
        if (i == in.size()) break;
        t->right = in[i] == "null" ? nullptr : new Node(parseInt(in[i]));
        q.push(t->right);
        i++;
    }
    return root;
}

class Solution {
    // unordered_map<Node*, pair<int, int>> map;

    pair<pair<int, int>, pair<int, int>> solve(Node* root) {

        // if (map.find(root) != map.end()) return map[root];
        if (!root) return {{0, 0}, {0, 0}};

        auto l = solve(root->left);
        auto r = solve(root->right);

        pair<int, int> ifin = {
            {root->data + l.second.first + r.second.first},
            {1 + l.second.second + r.second.second}
        };
        pair<int, int> lIfout, rIfout;

        if (l.first.first > l.second.first) {
            lIfout = {l.first.first, l.first.second};
        }
        else lIfout = {l.second.first, l.second.second};

        if (r.first.first > r.second.first) {
            rIfout = {r.first.first, r.first.second};
        }
        else rIfout = {r.second.first, r.second.second};

        pair<int, int> ifout = {lIfout.first + rIfout.first, lIfout.second + rIfout.second};
        
        return {ifin, ifout};
    }
public:
    int LISS(struct Node *root) {
        // map.clear();
        auto [rootUsed, notUsed] = solve(root);
        
        if (rootUsed.first > notUsed.first) {
            cout << rootUsed.first << endl;
            return rootUsed.second;
        }
        if (rootUsed.first == notUsed.first) {
            cout << rootUsed.first << endl;
            return max(rootUsed.second, notUsed.second);
        }
        cout << notUsed.first << endl;
        return notUsed.second;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    Node* root = buildTree();
    Solution obj;
    cout << obj.LISS(root);
}