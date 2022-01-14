#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int mod = int(1e9 + 7);
public:
    long long countWays(int n, int k){
        if (n == 1) return k;
        if (k == 1) {
            if (n > 2) return 0;
            return 1;
        }

        long long prevDiff = k * (k - 1);
        long long prevTot = prevDiff + k;
        long long same, diff;

        for (int i = 2; i < n; i++) {
            same = prevDiff;
            diff = ((prevTot % mod) * (k - 1)) % mod;

            prevTot = (same % mod + diff % mod) % mod;
            prevDiff = diff; 
        }
        return (prevTot) % mod;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    Solution obj;
    cout << obj.countWays(n, k);
}
