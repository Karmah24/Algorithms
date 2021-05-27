#include <bits/stdc++.h>
using namespace std;

#define ll long long
//=======================

class Solution {
public:
    ll getMaxArea(ll arr[], int n) {

        stack<int> s;
        ll res = 0, tp, area;
        int i = 0;
        while (i < n) {
            if (s.empty() || arr[s.top()] <= arr[i]) s.push(i++);

            else {
                tp = s.top();
                s.pop();
                area = arr[tp] * (s.empty() ? i : i - s.top() - 1);
                res = max(res, area);
            }
        }
        while (!s.empty()) {
            tp = s.top();
            s.pop();
            area = arr[tp] * (s.empty() ? n : n - 1 - s.top());
            res = max(res, area);
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    cout << obj.getMaxArea(arr, n);
}
