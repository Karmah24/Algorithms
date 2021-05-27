#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

ListNode* buildList(int size) {
    int val;
    cin >> val;
    
    ListNode* head = new ListNode(val);
    ListNode* tail = head;
    
    for (int i=0; i<size-1; i++) {
        cin>> val;
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    return head;
}

void printList(ListNode* n) {
    while (n) {
        cout<< n->val << " ";
        n = n->next;
    }
    cout << endl;
}

class Solution {
    pair<ListNode*, ListNode*> getMid(ListNode* head) {

        ListNode *mid = head, *fast = head, *prev;
        while (fast && fast->next) {
            prev = mid;
            mid = mid->next;
            fast = fast->next->next;
        }
        return {prev, mid};
    }
    ListNode* mergeTwoLists(ListNode *a, ListNode *b) {

        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        
        while (a && b) {
            if (a->val < b->val) {
                tail->next = a;
                a = a->next;
            }
            else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        ListNode *rem = a ? a : b;
        while (rem) {
            tail->next = rem;
            rem = rem->next;
            tail = tail->next;
        }
        return head->next;
    }
public:
    ListNode* sortList(ListNode *head) {

        if (!head || !head->next) return head;

        auto[prev, mid] = getMid(head);
        prev->next = nullptr;

        ListNode *lo = sortList(head);
        ListNode *hi = sortList(mid);

        return mergeTwoLists(lo, hi);
    }
};

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, m;
    cin >> n;
    ListNode* head = buildList(n);
    Solution obj;
    ListNode* res = obj.sortList(head);
    printList(res);
}