#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define T first
#define F second
const ll M = 1003;

class Solution {
    vector<vector<pair<ll, ll>>> dp;

    pair<ll, ll> solve(string& str, int l, int r) {
        
        if (l == r) {
            if (str[l] == 'T') return {1, 0};
            else return {0, 1};
        }
        if (dp[l][r].T != -1) return dp[l][r];
        
        dp[l][r] = {0, 0};
        ll tr, fl;
        for (int i = l + 1; i < r; i += 2) {
            
            pair<ll, ll> lo = solve(str, l, i - 1), hi = solve(str, i + 1, r);
            ll loTot = (lo.T + lo.F) % M, hiTot = (hi.T + hi.F) % M;
            
            switch(str[i]) {
                
                case('&'):
                    tr = (lo.T * hi.T) % M;
                    fl = (((loTot * hiTot) % M) - tr + M) % M;
                    break;
                case('|'):
                    fl = (lo.F * hi.F) % M;
                    tr = (((loTot * hiTot) % M) - fl + M) % M;
                    break;
                case('^'):
                    tr = (((lo.T * hi.F) % M) + ((lo.F * hi.T) % M)) % M;
                    fl = (((lo.T * hi.T) % M) + ((lo.F * hi.F) % M)) % M;
                    break;
            }
            dp[l][r].T = (dp[l][r].T + tr) % M;
            dp[l][r].F = (dp[l][r].F + fl) % M;
        }
        return dp[l][r];
    }
public:
    int countWays(int n, string str) {

        dp = vector<vector<pair<ll, ll>>>(n, vector<pair<ll, ll>>(n, {-1, -1}));
        return solve(str, 0, n - 1).T;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    string str;
    cin >> str;
    Solution obj;
    cout << obj.countWays(n, str);
}