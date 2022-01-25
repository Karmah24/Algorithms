#include <bits/stdc++.h>
using namespace std;
#define ll long long
//=======================

ll solve() {
    
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    unordered_map<char, int> cnt;
    for (auto &ch: str) cnt[ch]++;
    ll pairs = 0;
    for (auto &p: cnt) {
        pairs += p.second / 2;
    }
    pairs = (pairs / k) * 2;
    return pairs + (n - (pairs * k) >= k);
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int T = 1;
    cin >> T;
    while (T--) {
        
        cout << solve() << '\n';
    }
    return 0;
}