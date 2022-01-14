#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<pair<int, ll>> factorize(ll n) {

    vector<pair<int, ll>> factors;
    int cnt = 0;
    while (n % 2 == 0) {
        cnt++;
        n /= 2;
    }
    if (cnt > 0) factors.push_back({cnt, 2});
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i != 0) continue;
        cnt = 0;
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
        factors.push_back({cnt, i});
    }
    if (n != 1) factors.push_back({1, n});
    return factors;
}

void solve() {

    ll n;
    cin >> n;
    vector<pair<int, ll>> factors = factorize(n);
    sort(factors.rbegin(), factors.rend());

    cout << factors[0].first << endl;
    for (int i = 0; i < factors[0].first - 1; i++) cout <<setprecision(0)<< factors[0].second << " ";
    cout <<setprecision(0)<< n / (pow(factors[0].second, factors[0].first - 1)) << endl;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}