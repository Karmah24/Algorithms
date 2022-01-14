#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

class Solution {
public:
    int concatenatedBinary(int n) {
        
        ll res = 0, l = 0;
        for (int i = 1; i <= n; i++) {

            if ((i & (i - 1)) == 0) l++;
            res = ((res << l) | i) % MOD;
        }
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    Solution obj;
    cout << obj.concatenatedBinary(n);
}