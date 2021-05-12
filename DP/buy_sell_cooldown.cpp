#include <bits/stdc++.h>
using namespace std;

#define fori(i, n) for (int i = 0; i < n; i++)
typedef pair<int, int>	pii;
typedef vector<int>		vi;
//=======================

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        pii cool, holding, sold;
        cool.first = sold.first = 0, holding.first = -prices[0];

        for (int i = 1; i < n; i++) {

            cool.second = max(cool.first, sold.first);
            holding.second = max(holding.first, cool.first - prices[i]);
            sold.second = holding.first + prices[i];

            cool.first = cool.second, holding.first = holding.second, sold.first = sold.second;
        }

        return max({cool.first, holding.first, sold.first});
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
 
    Solution obj;
    int n;
    cin >> n;
    vi prices(n);
    fori (i, n) cin >> prices[i];
    cout << obj.maxProfit(prices) << endl;
}
