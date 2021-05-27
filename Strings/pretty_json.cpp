#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> solve(string str) {

        vector<string> res;
        unordered_set<char> braces;
        braces.insert('{');
        braces.insert('[');
        braces.insert('}');
        braces.insert(']');

        int tabs = 0;
        string line = "";
        for (char ch: str) {

            char last = line != "" ? line[line.size() - 1] : ' ';
            if ((last == ']' || last == '}') && ch != ',') {
                res.push_back(line);
                line.erase(tabs);
            }
            if (braces.find(ch) != braces.end()) {

                if (line != "" && line[line.size() - 1] != '\t') res.push_back(line);
                line.erase(tabs);

                if (ch == '{' || ch == '[') {
                    
                    res.push_back(line + ch);
                    line.push_back('\t');
                    tabs++;
                }
                else {
                    line.pop_back();
                    line.push_back(ch);
                    tabs--;
                }
                continue;
            }
            line.push_back(ch);
            if (ch == ',') {
                res.push_back(line);
                line.erase(tabs);
            }
        }
        res.push_back(line);
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
    for (string s: obj.solve(str)) cout << s << endl;
}