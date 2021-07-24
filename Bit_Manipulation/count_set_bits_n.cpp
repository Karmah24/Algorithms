#include <bits/stdc++.h>
using namespace std;

class Solution {

    int getMaxPower(int n) {
        int x = 0;
        while ((1 << x) <= n) x++;

        return x - 1;
    }
public:
    int countSetBits(int n, int a = 0) {
        if (n <= 0) return a;
        // int x = getMaxPower(n + 1);
        int x = floor(log2(n + 1));
        a += (1 << (x - 1)) * x;
        a += n - (1 << x) + 1;
        return countSetBits(n - (1 << x), a);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    Solution obj;
    cout << obj.countSetBits(n);
}
