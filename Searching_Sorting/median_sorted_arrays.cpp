 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double median(vector<int> &A, vector<int> &B) {

        int n = A.size(), m = B.size();
        if (n > m) return median(B, A);
        int req = (n + m + 1) / 2;

        int lo = 0, hi = n;

        while (lo <= hi) {

            int cut1 = (lo + hi) / 2;
            int cut2 = req - cut1;

            int l1 = cut1 == 0 ? INT_MIN : A[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : B[cut2 - 1];
            int r1 = cut1 == n ? INT_MAX : A[cut1];
            int r2 = cut2 == m ? INT_MAX : B[cut2];

            if (l1 <= r2 && l2 <= r1) {
                if ((n + m) % 2 != 0) return max(l1, l2);
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if (l1 > r2) hi = cut1 - 1;
            else lo = cut1 + 1;
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