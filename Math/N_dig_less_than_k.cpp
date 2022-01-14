#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dig(int n) {
        int i = 0;
        while (n) {
            i++;
            n /= 10;
        }
        return i;
    }
    int util(vector<int>& A, int B, int C, int d) {

        if (C == 0) return 0;
        int fd =  C / (int)pow(10, d - 1);
        int x = lower_bound(A.begin(), A.end(), fd) - A.begin();

        if (x == 0) return 0;
        int res = x * pow(A.size(), B - 1);
        return res + util(A, B - 1, C % (int)pow(10, d - 1), d - 1);
    }
public:
    int solve(vector<int>& A, int B, int C) {

        int d = dig(C), n = A.size();
        if (B > d || n == 0) return 0;
        if (B < d) {
            if (B == 1) return n;
            if (A[0] == 0) return n - 1 * (pow(n, B - 1));
            return pow(B, n);
        }
        int res = 0, fd = C / (int)pow(10, d - 1);
        int x = lower_bound(A.begin(), A.end(), fd) - A.begin();

        if (B == 1) return x;

        if (A[0] == 0) x--;
        if (x == 0) return 0;
        res += x * pow(n, B - 1);
        res += util(A, B - 1, C % (int)pow(10, d - 1), d - 1);
        
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    int B, C;
    cin >> B >> C;
    Solution obj;
    cout << obj.solve(A, B, C);
}