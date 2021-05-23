#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // O(log(n)) time and space (recursion stack)
    int rec_pow(int x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;

        int res = pow(x, n / 2);
        res *= res;
        if (n % 2 == 0) return res;
        return res * x;
    }
    // O(log(n)) time O(1) space
    int bit_pow(int x, int n) {
        if (x == 0) return 0;
        int res = 1;
        while (n) {
            if (n & 1) {
                res *= x;
            }
            x *= x;
            n = n >> 1;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int x, n;
    cin >> x >> n;
    Solution obj;
    cout << obj.bit_pow(x, n);
}