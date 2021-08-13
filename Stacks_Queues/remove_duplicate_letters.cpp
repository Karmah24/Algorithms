#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string &s) {
        
        int n = s.size();
        vector<int> count(26, 0);
        vector<bool> isIn(26, false);

        for (char &ch: s) count[ch - 'a']++;

        stack<char> st;

        for (char &ch: s) {
            int x = ch - 'a';

            count[x]--;
            if (isIn[x]) continue;
            while (!st.empty() && st.top() > ch && count[st.top() - 'a'] > 0) {
                isIn[st.top() - 'a'] = false;
                st.pop();
            }
            isIn[x] = true;
            st.push(ch);
        }
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string s;
    cin >> s;    
    Solution obj;
    cout << obj.removeDuplicateLetters(s);
}