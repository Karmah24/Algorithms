#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
//=======================

const int N = 1e4;
int spf[N + 1];
int fac_prod[N];

void sieve() {
    memset(spf, -1, sizeof(spf));

    for (int p = 2; p * p <= N; p++) {
        if (spf[p] != -1) continue;
        for (int i = p * p; i <= N; i += p) {
            if (spf[i] == -1) spf[i] = p;
        }
    }
}
int factorize(int n) {

    if (fac_prod[n] != -1) return fac_prod[n];

    int a = n, fac = spf[n], res = 1;

    while (fac != -1) {

        while (a % fac == 0) a /= fac;
        res *= fac;
        fac = spf[a];
    }
    if (a != 1) res *= a;
    return fac_prod[n] = res;
}

bool solve(int a, int b) {

    // return b % factorize(a) == 0;

    while (true) {

        int prev = a;
        a /= gcd(a, b);
        if (a == 1) return true;
        if (prev == a) return false;
    }
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // sieve();
    // memset(fac_prod, -1, sizeof(fac_prod));

    int T = 1;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        if (solve(a, b)) cout << "YES" << ln;
        else cout << "NO" << ln;
    }
    return 0;
}