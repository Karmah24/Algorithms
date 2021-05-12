#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for (int i = 0; i < n; i++)
typedef vector<int>		vi;
const int N = 3e5;
//=======================
int en[N];

void pairup(string s) {
    stack<int> stack;
    loop (i, s.size()) {
        if (s[i] == '(')
            stack.push(i);
        else {
            int t = stack.top();
            en[t] = i;
            stack.pop();
        }
    }   
}
int solve(string s, int lo, int hi) {
    if (lo == hi - 1)
        return 1;
    if (en[lo] == hi)
        return 2 * solve(s, lo + 1, hi - 1);
    else
        return solve(s, lo, en[lo]) + solve(s, en[lo]+1, hi);
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
        cout << solve(s, 0, s.size() - 1) << endl;
    }
    return 0;
}