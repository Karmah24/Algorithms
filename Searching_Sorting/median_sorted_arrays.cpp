#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double median(vector<int>& A, vector<int>& B) {

        if (A.size() > B.size()) return median(B, A);
        int n = A.size(), m = B.size();

        int l = 0, r = n, req = (n + m + 1) / 2, i, j;

        if (l == r && l == 0) {
            if (m % 2 != 0) return B[req - 1];
            return (B[req - 1] + B[req]) / 2.0;
        }
        while (l <= r) {
            i = (l + r) / 2;
            j = req - i;

            if (i > n) {
                r = i - 1;
                continue;
            }
            if (j > m) {
                l = i + 1;
                continue;
            }

            if ((i == 0 || j == m || A[i - 1] <= B[j]) && (j == 0 || i == n || B[j - 1] <= A[i])) {
                
                int lo, hi;
                if (i == 0) lo = B[j - 1];
                else if (j == 0) lo = A[i - 1];
                else lo = max(A[i - 1], B[j - 1]);
                if ((n + m) % 2 == 1) return lo;
                if (i == n) hi = B[j];
                else if (j == m) hi = A[i];
                else hi = min(A[i], B[j]);
                return (lo + hi) / 2.0;
            }
            if (i != 0 && j != m && A[i - 1] > B[j]) r = i - 1;
            else l = i + 1;
        }
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<int> arr1(n), arr2(m);
    for (int i = 0; i < n; i++) cin >> arr1[i];
    for (int i = 0; i < m; i++) cin >> arr2[i];
    Solution obj;
    cout << obj.median(arr1, arr2);
}