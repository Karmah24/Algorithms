#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& A) {

        int res = 0;
        for (int i = 0; i < 32; i++) {
            
            int x = 1 << i, ones = 0;
            for (int e: A) {
                if (x & e) ones++;
            }
            if (ones % 3 == 1) res += x;
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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    cout << obj.solve(arr);
}