// rectangle overlap
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define w first
#define b second
//=======================

bool isWhite(ll r, ll c) {
    return (r + c) % 2 == 0;
}
pair<ll, ll> white_black(ll n, ll m) {
    if (n < 0 || m < 0) return {0, 0};
    return {(n * m + 1) / 2, (n * m) / 2};
}
pair<ll, ll> solve() {
    
    ll n, m; 
    cin >> n >> m;
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    auto T = white_black(n, m);
    auto W = white_black(y2 - y1 + 1, x2 - x1 + 1);
    if (!isWhite(y1, x1)) swap(W.w, W.b);
    auto B = white_black(y4 - y3 + 1, x4 - x3 + 1);
    if (!isWhite(y3, x3)) swap(B.w, B.b);
    auto O = white_black(min(y4, y2) - max(y3, y1) + 1, min(x4, x2) - max(x3, x1) + 1);
    if (!isWhite(max(y3, y1), max(x3, x1))) swap(O.w, O.b);
    T.w += W.b - B.w - O.b;
    T.b += B.w - W.b + O.b;
    return T;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int T = 1;
    cin >> T;
    while (T--) {
        
        auto [f, s] = solve();
        cout << f << " " << s << '\n';
    }
    return 0;
}