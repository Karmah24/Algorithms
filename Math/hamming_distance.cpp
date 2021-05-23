#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1000000007;

class Solution {
    int hammingDis(int a, int b) {
        
        int x = a ^ b;
        int d = 0;
        while (x) {
            d = (d % MOD) + 1;
            x = x & (x - 1);
        }
        return d % MOD;
    }
public:
    int hammingDistance1(vector<int>& arr) {
            
        int res = 0, n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                
                res = ((res % MOD) + (hammingDis(arr[i], arr[j]) % MOD)) % MOD;
            }
        }
        return ((res % MOD) * 2) % MOD;
    }
    int hammingDistance(vector<int>& arr) {

        ll ones, zeros, res = (ll)0;

        for (int i = 0; i < 32; i++) {

            ones = zeros = (ll)0;
            int x = 1 << i;

            for (int j = 0; j < arr.size(); j++) {
                if (arr[j] & x) ones = ((ones % MOD) + 1) % MOD;
                else zeros = ((zeros % MOD) + 1) % MOD;
            }
            if (ones == 0 || zeros == 0) continue;
            ll m = ((ones % MOD) * (zeros % MOD)) % MOD;
            res = ((res % MOD) + (m * 2) % MOD) % MOD;
        }
        return res % MOD;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    cout << obj.hammingDistance(arr);
}