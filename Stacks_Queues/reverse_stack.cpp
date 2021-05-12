#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>& s, int x) {

    if (s.empty()) s.push(x);
    else {
        int a = s.top();
        s.pop();
        insertAtBottom(s, x);
        s.push(a);
    }
}
void reverse(stack<int>& s) {
    
    if (s.size() == 0) return;
    int x = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s, x);
}

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    stack<int> s;
    int n;
    cin >> n;
    while (n--) {
        int k;
        cin >> k;
        s.push(k);
    }
    reverse(s);
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}