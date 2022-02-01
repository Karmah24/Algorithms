#include <bits/stdc++.h>
using namespace std;
#define int long long
//=======================
const int N = 1e6 + 1;
bool prime[N];

void sieveOfEratosthenes() {
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    for (int p = 2; p * p <= N; p++) {
        if (!prime[p]) continue;
        for (int i = p * p; i <= N; i += p) prime[i] = false;
    }
}
int solve() {

    int n, e;
    cin >> n >> e;
    vector<int> arr(n), vis(n, false);
    vector<int> primes;
    for (int i = 0; i < n; i++)  {
        cin >> arr[i];
        if (prime[arr[i]]) primes.push_back(i);
    }
    unordered_map<int, int> pre, post;
    for (int i = 0; i < e; i++) {
        int cnt = 0;
        for (int j = i; j < n; j += e) {
            if (arr[j] == 1) cnt++;
            else {
                if (prime[arr[j]]) pre[j] = cnt;
                cnt = 0;
            }
        }
    }
    for (int i = n - 1; i > n - 1 - e; i--) {
        int cnt = 0;
        for (int j = i; j >= 0; j -= e) {
            if (arr[j] == 1) cnt++;
            else {
                if (prime[arr[j]]) post[j] = cnt;
                cnt = 0;
            }
        }
    }
    int res = 0;
    for (auto &e: primes) {
        res += (pre[e] * post[e]) + pre[e] + post[e];
    }
    return res;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int T = 1;
    cin >> T;
    sieveOfEratosthenes();
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}