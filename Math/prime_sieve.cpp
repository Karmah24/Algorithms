#include <bits/stdc++.h>
using namespace std;

const int N = 1e9;
bool prime[N];

void sieveOfEratosthenes() {
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p < N; p++) {
        if (!prime[p]) continue;
        for (int i = p * p; i < N; i += p) prime[i] = false;
    }
}