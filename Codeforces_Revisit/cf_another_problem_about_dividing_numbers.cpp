#include <bits/stdc++.h>
using namespace std;
//================================================================
const int N = 4e4;
vector<bool> isPrime(N, true);
vector<int> primes;

void sieveOfEratosthenes() {
    isPrime[1] = false;
    for (int p = 2; p * p < N; p++) {
        if (!isPrime[p]) continue;
        for (int i = p * p; i < N; i += p) isPrime[i] = false;
    }
    for (int i = 2; i < N; i++) if (isPrime[i]) primes.push_back(i);
}
int prime_exps(int n) {
    int cnt = 0;
    for (auto &prime: primes) {
        while (n % prime == 0) {
            cnt++;
            n /= prime;
        }
    }
    return cnt + (n > 1);
}
bool solve() {
    int a, b, k;
    cin >> a >> b >> k;
    if (k == 1) return (a != b) && ((a % b == 0) || (b % a == 0));
    return prime_exps(a) + prime_exps(b) >= k;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    sieveOfEratosthenes();
    int T = 1;
    cin >> T;
    while (T--) {
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}