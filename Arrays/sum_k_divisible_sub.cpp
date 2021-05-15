#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
typedef vector<int>		vi;
//=======================

class Solution {
public:
    int solve(vi& arr, int n, int k) {

        int rem[k - 1];
        memset(rem, -1, sizeof rem);
        int res = 0, sum = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum == 0) continue;
            if (sum % k == 0) res = i + 1;
            else {
                if (rem[((sum % k) + k) % k - 1] == -1) rem[((sum % k) + k) % k - 1] = i;
                else res = max(res, i - rem[((sum % k) + k) % k - 1]);
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, k;
    cin >> n;
    vi arr(n);
    loop(i, n) cin >> arr[i];
    cin >> k;
    Solution obj;
    cout << obj.solve(arr, n, k);
}
