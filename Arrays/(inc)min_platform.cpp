#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define F first
#define S second
typedef pair<int, int>	pii;
typedef vector<pii>		vpii;
const int mod = int(1e9 + 7);
const int N = 3e5, M = N;
//=======================

void solve() {
    int n, k;
    cin >> n;
    vpii times(n);
    loop (i, n) cin >> times[i].F;
    loop (i, n) cin >> times[i].S;
    sortall(times);
    
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();

    }
    return 0;
}