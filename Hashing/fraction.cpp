#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    string fractionToDecimal(int A, int B) {
        
        ll a = A, b = B;

        string res = a * b < 0 ? "-" : "";

        a = abs(a);
        b = abs(b);
        res += to_string((ll)a / b);

        if (a % b == 0) return res;
        ll x = a % b;
        string rep = "";
        unordered_map<int, int> m;
        int i = 0;
        while (x != 0 && m.find(x) == m.end()) {

            m[x] = i++;
            x *= 10;
            rep += to_string(x / b);
            x %= b;

        }
        res += ".";
        if (x == 0) return res + rep;
        return res + rep.substr(0, m[x]) + "(" + rep.substr(m[x], rep.size() - m[x]) + ")";
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int a, b;
    cin >> a >> b;
    Solution obj;
    cout << obj.fractionToDecimal(a, b);
}