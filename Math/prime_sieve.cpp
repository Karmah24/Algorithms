#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int spf[N];
vector<int> primes;

void sieve() {
    memset(spf, -1, sizeof(spf));
    for (int p = 2; p * p < N; p++) {
        if (spf[p] != -1) continue;
        spf[p] = p;
        for (int i = p * p; i < N; i += p) {
            if (spf[i] == -1) spf[i] = p;
        } 
    }
    for (int i = 2; i < N; i++) {
        if (spf[i] == -1) spf[i] = i;
        if (spf[i] == i) primes.push_back(i);
    }
}

vector<bool> is_prime(N, true);
vector<int> primes;

void sieve() {
    is_prime[1] = false;
    for (int p = 2; p * p < N; p++) {
        if (!is_prime[p]) continue;
        for (int i = p * p; i < N; i += p) is_prime[i] = false;
    }
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) primes.push_back(i);
    }
}