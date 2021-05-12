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

class Solution {
public:
    void removeLoop(Node* head) {

       if (!head || !head->next) return; 
        Node *hare, *tor;
        hare = head->next->next;
        tor = head->next;

        while (tor->data != hare->data) {

            if (!tor || !hare || !hare->next) return;
            tor = tor->next;
            hare = hare->next->next;
        }
        tor = head;
        while (tor->data != hare->data) {
            tor = tor->next;
            hare = hare->next;
        }
        while (hare->next->data != tor->data) hare = hare->next;
        hare->next = nullptr;
    }
};