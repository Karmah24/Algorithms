#include <bits/stdc++.h>
using namespace std;

#define ll long long
//=======================

class Solution {
public:
    vector<ll> firstNegative(int arr[], int n, int k) {

        queue<int> q;
        vector<ll> res;
        int i = 0, j = 0;

        while (j < k) if (arr[j++] < 0) q.push(j - 1);
        ll firstNeg = q.empty() ? 0 : arr[q.front()];
        res.push_back(firstNeg);

        while (j < n) {
            if (!q.empty() && i == q.front()) q.pop();
            i++;
            if (arr[j++] < 0) q.push(j - 1);
            firstNeg = q.empty() ? 0 : arr[q.front()];
            res.push_back(firstNeg);
        }
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    for (ll e: obj.firstNegative(arr, n, k)) cout << e << " ";
}