#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
    unsigned int solve(ll a, ll b, int res = 0) {

        if (a < b) return res;
        int i = 0;
        while ((b << i) <= a) {
            i++;
        }
        int x = b << (i - 1);
        res += 1 << (i - 1);
        return solve(a - x, b, res);
    }
public:
    unsigned int divide(int n, int m) {

        ll a = n, b = m;
        if (b == 0) return INT_MAX;
        if (b == 1) return a;
        if (a == INT_MIN && b == -1) return INT_MAX;

        int sign = a < 0 ^ b < 0 ? -1 : 1;
        b = abs(b); a = abs(a);
        return solve(a, b) * sign;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int a, b;
    cin >> a >> b;
    Solution obj;
    cout << obj.divide(a, b);
}