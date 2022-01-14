#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int>& s, int x) {

    if (s.empty() || x > s.top()) s.push(x);
    else {
        int a = s.top();
        s.pop();
        sortedInsert(s, x);
        s.push(a);
    }
}
void sort(stack<int>& s) {
    
    if (s.size() == 0) return;
    int x = s.top();
    s.pop();
    sort(s);
    sortedInsert(s, x);
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
    sort(s);
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}