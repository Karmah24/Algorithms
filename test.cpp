#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve() {
        
        int n = 5;
        bitset<10> x(n);
        bitset<10> y(~n);
        cout << x.to_string() << endl;
        cout << y.to_string() << endl;
        bitset<10> z(x & y);
        cout << z.to_string() << endl;
        cout << (x & y);

        string s1 = "hot", s2 = "cog";
        cout << s1.compare(s2);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Solution obj;
    obj.solve();
}