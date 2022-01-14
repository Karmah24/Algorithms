#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left = nullptr, *right = nullptr;
    Node(int x) : data(x) {}
};

Node* ipTree() {

    vector<string> in;
    string s;
    while (getline(cin, s, ' ')) in.push_back(s);

    Node *root = new Node(stoi(in[0]));
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < in.size()) {
        Node* t = q.front();
        q.pop();

        t->left = in[i] == "N" ? nullptr : new Node(stoi(in[i++]));
        if (t->left) q.push(t->left);

        if (i == in.size()) break;

        t->right = in[i] == "N" ? nullptr : new Node(stoi(in[i++]));
        if (t->right) q.push(t->right);
    }
    return root;
}

class Solution {
    
    Node *prev, *head;
    
    void convert(Node *u) {
        
        if (!u) return;
        
        Node *l = u->left;
        Node *r = u->right;
        if (!prev) head = u;
        else {
            u->left = prev;
            prev->right = u;
        }
        prev = u;
        
        convert(l);
        convert(r);
    }
    public: 
    Node * bToDLL(Node *root) {
        
        prev = nullptr;
        convert(root);
        return head;
    }
};
int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    Node *root = ipTree();
    Solution obj;
    Node *dll = obj.bToDLL(root);
    while (dll) {
        cout << dll->data << " ";
        dll = dll->right;
    }
}