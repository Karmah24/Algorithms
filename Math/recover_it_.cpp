#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2750132;

int gpf[N];
unordered_map<int, int> primeIdx;

void sieve() {
    memset(gpf, -1, sizeof(gpf));
    int idx = 1;
    for (ll p = 2; p < N; p++) {

        if (gpf[p] == -1) primeIdx[p] = idx++;
        for (ll i = p * 2; i < N; i += p) gpf[i] = p;
    }
}
void solve() {

    int n, x;
    cin >> n;
    multiset<int, greater<int>> st;
    for (int i = 0; i < 2 * n; i++) {
        cin >> x;
        st.insert(x);
    }
    while (!st.empty()) {
        x = *st.begin();
        if (gpf[x] == -1) {
            st.erase(st.find(x));
            st.erase(st.find(primeIdx[x]));
            cout << primeIdx[x] << " ";
        }
        else {
            st.erase(st.find(x));
            st.erase(st.find(gpf[x]));
            cout << x << " ";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed);

    sieve();
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}