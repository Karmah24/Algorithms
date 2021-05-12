#include <bits/stdc++.h>
using namespace std;

#define fori(i, n) for (int i = 0; i < n; i++)
//=======================

class Solution {
public:
    int findPages(int arr[], int n, int m) {

        int lo = INT_MIN, hi = 0;
        fori (i, n) {
            lo = max(arr[i], lo);
            hi += arr[i];
        }

        int res = INT_MAX;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int x = 1, pages_x = 0, i = 0;
            while (i < n && x <= m) {
                if (pages_x + arr[i] <= mid) {
                    pages_x += arr[i++];
                }
                else {
                    x++;
                    pages_x = 0;
                }
            }
            if (x > m) {
                lo = mid + 1;
                continue;
            }
            res = mid;
            hi = mid - 1;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, m;
    cin >> n;
    int arr[n];
    fori (i, n) cin >> arr[i];
    cin >> m;
    Solution obj;
    cout << obj.findPages(arr, n , m);
}
