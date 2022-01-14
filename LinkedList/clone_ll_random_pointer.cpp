#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next, *arb;

    Node(int data) {
        this->data = data;
        next = arb = NULL;
    }
};

Node* create(int n) {
    Node *head = NULL, *p, *temp;
    int k; 
    for(int i = 0; i < n; i++) { 
        cin >> k;
        temp = new Node(k);
        if (head == NULL) 
            head = temp;
        else {
            p = head;
            while (p->next)
                p = p->next;
            p->next = temp;
        }
    }
    return head;
}

void dis(Node *head){
    Node* p = head;
    while(p != NULL){
        string next, arb;
        next = p->next ? to_string(p->next->data) : "null";
        arb = p->arb ? to_string(p->arb->data) : "null";
        cout << p->data << "(" + next + ", " + arb + ") "; 
        p = p->next;
    }
    cout << endl;
}

Node* copyList(Node *head) {
    Node *p = head;
    while (p) {
        Node *copy = new Node(p->data);
        copy->next = p->next;
        p->next = copy;
        p = copy->next;
    }
    p = head;
    Node *new_head = p->next;
    while (p) {
        p->next->arb = p->arb ? p->arb->next : NULL;
        p = p->next->next;
    }
    Node *temp;
    p = head;
    while (p) {
        if (p->next->next) {
            temp = p->next->next;
            p->next->next = temp->next;
            p->next = temp;
        }
        else
            p->next = NULL;
        p = p->next;
    }
    return new_head;
}
int main() {
    int n, m, a, b;
    cin >> n >> m;
    Node *head = create(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        Node *p = head;
        for (int j = 0; j < a - 1; j++)
            p = p->next;
        Node *from = p;
        p = head;
        for (int j = 0; j < b - 1; j++)
            p = p->next;
        from->arb = p;
    }
    dis(head);
    head = copyList(head);
    dis(head);
    
    return 0;
}