#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1000003;

class Solution {
    ll fact(int n, ll res) {
        if (n == 1 || n == 0) return res;
        return fact(n - 1, res * n);
    }
public:
    int findRank(string str) {

        string s = str;
        sort(s.begin(), s.end());

        int n = str.size(), i = 0;
        ll res = (ll)1;

        while (i < n - 1) {

            int x = lower_bound(s.begin(), s.end(), str[i]) - s.begin();
            
            if (x != 0) res += (x * fact(n - i - 1, (ll)1)) % MOD;
            res %= MOD;
            s.erase(s.begin() + x);
            i++;
        }

        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string str;
    cin >> str;
    Solution obj;
    cout << obj.findRank(str);
}