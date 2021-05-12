#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
//=======================

class Solution {
public:
    string simplifyPath(string path) {
        
        bool rel = (path[0] != '/');
        vector<string> tokens;
        string token;
        istringstream iss(path);
        while (getline(iss, token, '/')) tokens.push_back(token);

        stack<string> stack;
        for (string s: tokens) {
            if (s == "." || s == "") continue;
            if (s == ".." && !stack.empty()) stack.pop();
            else if (s != "..") stack.push(s); 
        }
        vector<string> finalList(stack.size());
        int i = stack.size() - 1;
        while (!stack.empty()) {
            finalList[i] = stack.top();
            stack.pop();
            i--;
        }
        string res = rel ? "" : "/";
        for (string s: finalList) res += s + "/";
        if (res != "/") res.pop_back();
        
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int T = 1;
    cin >> T;
    cin.ignore();
    while (T--) {
        string path;
        cin >> path;
        Solution obj;
        cout << obj.simplifyPath(path) << endl;
    }
}
