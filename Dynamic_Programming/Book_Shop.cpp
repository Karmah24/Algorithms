#include <bits/stdc++.h>
using namespace std;
 
int maxPages(int n, int x, vector<int> &price, vector<int> &pages) {

    vector<int> dp(x + 1, 0);
 
    for (int i = 0; i < n; i++) {
 
        for (int j = x; j >= price[i]; j--) {
            
            dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
        }
    }
    return dp[x];
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int n, x;
    cin >> n >> x;
    vector<int> price(n), pages(n);
    for (int i = 0; i < n; i++) cin >> price[i];
    for (int i = 0; i < n; i++) cin >> pages[i];
    cout << maxPages(n, x, price, pages);
}