#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBitonic(vector<int>& arr) {
        
        int n = arr.size();
        if (n == 0 || n == 1) return n;

        int inc[n], dec[n];
        for (int i = 0; i < n; i++) {
            inc[i] = dec[i] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i] && inc[j] + 1 > inc[i]) {
                    inc[i] = inc[j] + 1;
                }
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (arr[j] < arr[i] && dec[j] + 1 > dec[i]) {
                    dec[i] = dec[j] + 1;
                }
            }
        }
        int res = 1;
        for (int i = 0; i < n; i++) {
            res = max(res, inc[i] + dec[i]);
        }
        return res - 1;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    cout << obj.longestBitonic(arr);
}