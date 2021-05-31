#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define ll long long

class Solution {
    ll dp[1001][1001];
    
    ll solve(int S[], int n, int m, int M) {
        
        if (n == 0) return 1;
        if (dp[n][m] != -1) return dp[n][m];
        if (m == M - 1) {
            return dp[n][m] = n % S[m] == 0 ? 1 : 0;
        }
        ll t = 0, i = 0;
        while (S[m] * i <= n) {
            t += solve(S, n - (S[m] * i), m + 1, M);
            i++;
        }
        return dp[n][m] = t;
    }
public:
    long long int count( int S[], int m, int n ) {
        
        memset(dp, -1, sizeof(dp));
        return solve(S, n, 0, m);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    int S[n];
    for (int i = 0; i < n; i++)  cin >> S[i];
    Solution obj;
    auto start = high_resolution_clock::now();
    cout << obj.count(S, m, n);
    auto stop = high_resolution_clock::now();
    cout << endl << duration_cast<microseconds>(stop - start).count();
}