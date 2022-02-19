#include <bits/stdc++.h>
using namespace std;

const int N = 4e4;
vector<bool> isPrime(N, true);
void sieveOfEratosthenes() {
    isPrime[1] = false;
    for (int p = 2; p * p <= N; p++) {
        if (!isPrime[p]) continue;
        for (int i = p * p; i <= N; i += p) isPrime[i] = false;
    }
}