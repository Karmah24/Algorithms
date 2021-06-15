#include <bits/stdc++.h>
using namespace std;

// single query
vector<pair<int, int>> factorize(int n) {

    vector<pair<int, int>> factors;
    int cnt = 0;
    while (n % 2 == 0) {
        cnt++;
        n /= 2;
    }
    if (cnt > 0) factors.push_back({2, cnt});
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i != 0) continue;
        cnt = 0;
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
        factors.push_back({i, cnt});
    }
    if (n != 1) factors.push_back({n, 1});
    return factors;
}

// multiple queries
const int N = 1e8;
int spf[N];

void sieve() {
    memset(spf, -1, sizeof(spf));
 
    for (int p = 2; p * p < N; p++) {
        if (spf[p] != -1) continue;
        for (int i = p * p; i < N; i += p) {
            if (spf[i] == -1) spf[i] = p;
        }
    }
}
vector<pair<int, int>> sieve_factorize(int n) {

    vector<pair<int, int>> factors;
    int fac = spf[n], cnt, p;

    while (fac != -1) {
        p = fac, cnt = 0;
        while (p == fac || n == fac) {
            cnt++;
            n /= p;
            p = (n == p ? p : spf[n]);
        }
        factors.push_back({fac, cnt});
        fac = p;
    }
    if (n != 1) factors.push_back({n, 1});
    return factors;
}

int main() {
    int n;
    cin >> n;
    sieve();
    for (auto p: sieve_factorize(n)) {
        cout << p.first << " " << p.second << endl;
    }
}