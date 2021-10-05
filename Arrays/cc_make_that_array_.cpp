#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
//=======================

ll solve(int n, vector<ll> &A, vector<ll> &B) {
    
    ll res = 0;

    for (int i = 0; i < n; i++) res -= A[i] * (i + 1);
    for (int i = 0; i < n; i++) res += B[i] * (i + 1);

    return res;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T = 1;
    cin >> T;
    while (T--) {
        
        int n;
        cin >> n;
        vector<ll> A(n), B(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < n; i++) cin >> B[i];

        cout << solve(n, A, B) << ln;
    }
    return 0;
}