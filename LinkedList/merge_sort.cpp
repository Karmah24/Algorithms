// Shivika Mahajan is an idiot

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

    Node* findMid(Node *head, Node *tail) {

        Node *slow = head, *fast = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node* merge(Node *a, Node *b) {

        Node *temp, *temp_tail;
        temp_tail = temp = new Node(0);
        while (a && b) {
            if (a->data <= b->data) {
                temp_tail->next = new Node(a->data);
                a = a->next;
            }
            else {
                temp_tail->next = new Node(b->data);
                b = b->next;
            }
            temp_tail = temp_tail->next;
        }
        Node *t = a ? a : b;
        while (t) {
            temp_tail->next = new Node(t->data);
            t = t->next;
            temp_tail = temp_tail->next;
        }
        return temp->next;
    }
    Node* sort(Node *head, Node *tail) {

        if (head == tail) return new Node(head->data);
        Node *mid = findMid(head, tail);
        Node *head1 = sort(head, mid);
        Node *head2 = sort(mid->next, tail);
        return merge(head1, head2);
    }
public:
    Node* mergeSort(Node *head) {

        Node *tail = head;
        while (tail->next) tail = tail->next;
        return sort(head, tail);
    }
};


int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, m;
    cin >> n;
    Node* head = buildList(n);
    Solution obj;
    Node* res = obj.mergeSort(head);
    printList(res);
}