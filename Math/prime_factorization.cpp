#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int spf[N];
vector<pair<int, int>> factors[N];

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

void sieve() {
    memset(spf, -1, sizeof(spf));
 
    for (int p = 2; p * p < N; p++) {
        if (spf[p] != -1) continue;
        for (int i = p; i < N; i += p) {
            if (spf[i] == -1) spf[i] = p;
        }
    }
}
vector<pair<int, int>> sieve_factorize(int n) {
    if (!factors[n].empty()) return factors[n];
    int a = n, cnt, fac = spf[n];
    while (a > 1) {
        cnt = 0;
        while (a % fac == 0) {
            cnt++;
            a /= fac;
        }
        factors[n].push_back({fac, cnt});
        fac = spf[a];
    }
    return factors[n];
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    sieve();
    for (auto p: sieve_factorize(n)) {
        cout << p.first << " " << p.second << endl;
    }
}