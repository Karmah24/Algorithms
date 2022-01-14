#include <bits/stdc++.h>
using namespace std;
#define ll long long
//=======================

ll solve() {
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    set<int> missing;
    vector<int> available;
    for (int i = 1; i <= n; i++) missing.insert(i);
    for (int e: arr) {
        if (e <= n && missing.count(e)) missing.erase(e);
        else available.push_back(e);
    }
    sort(available.begin(), available.end());
    for (int e: available) {
        int to_get = *missing.begin();
        if (e <= 2 * to_get) return - 1;
        missing.erase(missing.begin());
    }
    return available.size();
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
        
        cout << solve() << '\n';
    }
    return 0;
}