#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList(int size) {
    int val;
    cin >> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for (int i=0; i<size-1; i++) {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    return head;
}

void printList(Node* n) {
    while (n) {
        cout<< n->data << " ";
        n = n->next;
    }
    cout << endl;
}

class Solution {
public:
    Node* findIntersection(Node* head1, Node* head2) {
        
        Node *res_head, *res_tail;
        res_head = res_tail = new Node(0);
        
        while (head1 && head2) {
            
            if (head1->data == head2->data) {
                res_tail->next = new Node(head1->data);
                res_tail = res_tail->next;
                head1 = head1->next;
                head2 = head2->next;
            }
            else if (head1->data > head2->data) head2 = head2->next;
            else head1 = head1->next;
        }
        return res_head->next;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n;
    Node* head1 = buildList(n);
    cin>>m;
    Node* head2 = buildList(m);
    Solution obj;
    Node* res = obj.findIntersection(head1, head2);
    printList(res);
}