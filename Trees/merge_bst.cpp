#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node *left = nullptr, *right = nullptr;
    Node(int x) : data(x) {}
};

class Solution {
    Node *prev;
    
    void convert(Node *u, Node *&head) {    // reference to pointer
        
        if (!u) return;
        
        convert(u->left, head);
        
        if (!prev) head = u;
        else {
            u->left = prev;
            prev->right = u;
        }
        prev = u;
        
        convert(u->right, head);
    }
public:
    vector<int> merge(Node *root1, Node *root2) {
        
        Node *head1, *head2;
        head1 = head2 = prev = nullptr;
        convert(root1, head1);
        prev = nullptr;
        convert(root2, head2);
        
        vector<int> res;
        while (head1 && head2) {
            
            if (head1->data <= head2->data) {
                res.push_back(head1->data);
                head1 = head1->right;
            }
            else {
                res.push_back(head2->data);
                head2 = head2->right;
            }
        }
        Node *t = (head1) ? head1 : head2;
        while (t) {
            res.push_back(t->data);
            t = t->right;
        }
        return res;
    }
};