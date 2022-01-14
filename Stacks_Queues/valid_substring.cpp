#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string str) {
        
        stack<int> s;
        s.push(-1);
        int st, res = 0;
        
        for (int i = 0; i < str.size(); i++) {
            
            if (str[i] == '(') s.push(i);
            else {
                s.pop();
                if (s.empty()) s.push(i);
                else {
                    res = max(res, i - s.top());
                }
            }
        }
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
    cout << obj.longestValidParentheses(str);
}