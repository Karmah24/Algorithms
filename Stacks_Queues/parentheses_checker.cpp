#include<bits/stdc++.h>

using namespace std;
#define fori(i, n) for (int i = 0; i < n; i++)
//=======================

string pairup(string s) {
    stack<char> stack;
    unordered_map<char, char> map;
    map[')'] = '(', map['}'] = '{', map[']'] = '[';
    fori (i, s.size()) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            stack.push(s[i]);
        else {
            if (stack.empty() || stack.top() != map[s[i]])
                return "not balanced";
            stack.pop();
        }
    }
    if(stack.empty())
        return "balanced";
    return "not balanced";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    string s;
    while (T--) {
        cin >> s;
        cin.ignore();
        pairup(s);
        cout << pairup(s) << endl;
    }
    return 0;
}