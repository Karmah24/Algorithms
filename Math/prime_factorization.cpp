#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
int spf[N];

// multiple queries
void sieve() {
    memset(spf, -1, sizeof(spf));

    for (int p = 2; p * p < N; p++) {
        if (spf[p] != -1) continue;
        spf[p] = p;
        for (int i = p * p; i < N; i += p) {
            if (spf[i] == -1) spf[i] = p;
        }
    }
    for (int i = 2; i < N; i++) if (spf[i] == -1) spf[i] = i;
}
vector<pair<int, int>> sieve_factorize(int n) {
    
    vector<pair<int, int>> factors;
    int cnt, fac = spf[n];
    while (n > 1) {
        cnt = 0;
        while (n % fac == 0) {
            cnt++;
            n /= fac;
        }
        factors.push_back({fac, cnt});
        fac = spf[n];
    }
    return factors;
}

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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n = 99371;
    // cin >> n;
    sieve();
    for (auto p: sieve_factorize(n)) {
        cout << p.first << " " << p.second << endl;
    }
}