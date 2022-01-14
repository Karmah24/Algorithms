#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            
            // if (arr[i] <= 0 || arr[i] > n + 1 || arr[i] == i + 1) continue;
            
            int x = arr[i], t;
            while (x > 0 && x <= n && arr[x - 1] != x) {
                
                t = arr[x - 1];
                arr[x - 1] = x;
                x = t;
            }
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    cout << obj.firstMissingPositive(arr);
}