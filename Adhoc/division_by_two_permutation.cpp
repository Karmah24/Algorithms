#include <bits/stdc++.h>
using namespace std;
#define ll long long
//=======================
    
unordered_map<int, int> cnt;
    
void down(int x) {
    
    while (x) {
        cnt[x]--;
        x /= 2;
    }
}
bool solve() {
    
    int n, x;
    cin >> n;
    cnt.clear();
    for (int i = 0; i < n; i++) {
        cin >> x;
        while (x) {
            if (x <= n) cnt[x]++;
            x /= 2;
        }
    }
    for (int i = n; i > 0; i--) {
    
        if (cnt[i] == 0) return false;
        down(i);
    }
    return true;
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
        
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}