#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;
ll add(ll x, ll y) {return ((x % MOD) + (y % MOD) % MOD);}
ll sub(ll x, ll y) {return ((x % MOD) - (y % MOD) + MOD) % MOD;}

int distinctSubseq(string s) {

    int n = s.size();
    vector<int> lastIdx(26, -1);
    ll dp[n + 1];
    dp[0] = 1;


    for (int i = 0; i < n; i++) {

        int x = s[i] - 'a';
        dp[i + 1] = add(dp[i], dp[i]);

        if (lastIdx[x] != -1) {
            dp[i + 1] = sub(dp[i + 1], dp[lastIdx[x]]);
        }
        lastIdx[x] = i;
    }
    return dp[n] - 1;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string s;
    cin >> s;
    cout << distinctSubseq(s);
}