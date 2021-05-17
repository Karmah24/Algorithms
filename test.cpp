#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
typedef pair<int, int>	pii;
typedef vector<int>		vi;
typedef vector<pii>		vpii;
typedef vector<vi>		vvi;
//=======================

class Solution {
public:
    int evaluatePostfix(string str) {
        stack<int> s;
        int a, b;
        for (char ch: str) {
            if (ch == '*' || ch == '/' || ch == '+' || ch == '-') {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                if (ch == '*') s.push(b * a);
                else if (ch == '/') s.push(b / a);
                else if (ch == '+') s.push(b + a);
                else s.push(b - a);
            }
            else s.push(ch - '0');
        }
        return s.top();
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string str;
    cin >> str;
    Solution obj;
    cout << obj.evaluatePostfix(str);
}
