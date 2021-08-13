#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next = nullptr;
    Node(int x) : data(x) {}
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
    Node* reverse(Node *head) {
        Node *prev, *curr, *next;
        curr = head;
        prev = nullptr;
        
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    Node* add(Node *a, Node *b) {
        
        Node *res_head, *res_tail;
        res_head = res_tail = new Node(0);

        int carry = 0, sum;
        while (a && b) {
            sum = a->data + b->data + carry;
            if (sum > 9) {
                carry = 1;
                sum -= 10;
            }
            else carry = 0;
            res_tail->next = new Node(sum);
            a = a->next;
            b = b->next;
            res_tail = res_tail->next;
        }
        Node *t = a ? a : b;
        while (t) {
            sum = t->data + carry;
            if (sum > 9) {
                carry = 1;
                sum -= 10;
            }
            else carry = 0;
            res_tail->next = new Node(sum);
            t = t->next;
            res_tail = res_tail->next;
        }
        if (carry) res_tail->next = new Node(1);

        return res_head->next;
    }
public:
    Node* addTwoLists(Node* first, Node* second) {
        return reverse(add(reverse(first), reverse(second)));        
    }
};

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, m;
    cin >> n;
    Node* first = buildList(n);
    cin>>m;
    Node* second = buildList(m);
    Solution obj;
    Node* res = obj.addTwoLists(first,second);
    printList(res);
}