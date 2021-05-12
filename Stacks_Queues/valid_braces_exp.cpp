#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string str) {
        
        stack<int> s;

        for (int i = 0; i < str.size(); i++) {    
            if (str[i] == ')') {
                if (s.empty()) str[i] = '#';
                else s.pop();
            }
            else if (str[i] == '(') s.push(i);
        }

        while (!s.empty()) {
            str[s.top()] = '#';
            s.pop();
        }
        string res = "";
        for (char& ch: str) if (ch != '#') res += ch;

        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string str;
    cin >> str;
    Solution obj;
    cout << obj.minRemoveToMakeValid(str);
}
