#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct triplet {
    int x, y, z;
    triplet(int x, int y, int z) : x(x), y(y), z(z) {}
};

class Solution {
    static const int MOD = 1e9 + 7, N = 1e5;
    bool first = true;
    int dp[4][4][4][N];
    vector<triplet> triplets;

    ll add(ll x, ll y) {
        return ((x % MOD) + (y % MOD)) % MOD;
    }
    void fillTriplets() {

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (i == j) continue;
                for (int k = 0; k < 4; k++) {
                    if (j == k) continue;
                    triplets.push_back(triplet(i, j, k));
                }
            }
        }
    }
    bool isSafe(triplet &t1, triplet &t2) {
        return (t1.x != t2.x && t1.y != t2.y && t1.z != t2.z);
    }
public:
    int numOfWays(int n) {

        if (first) {
            fillTriplets();
            first = false;
        }
        for (int i = 0; i < n; i++) {

            for (auto &t1: triplets) {

                if (i == 0) {
                    dp[t1.x][t1.y][t1.z][i] = 1;
                    continue;
                }
                ll curr = 0;
                for (auto &t2: triplets) {
                    if (isSafe(t1, t2)) curr = add(curr, dp[t2.x][t2.y][t2.z][i - 1]);
                }
                dp[t1.x][t1.y][t1.z][i] = curr;
            }
        }
        ll res = 0;
        for (auto t: triplets) {
            res = add(res, dp[t.x][t.y][t.z][n - 1]);
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
    cout << obj.numOfWays(n);
}