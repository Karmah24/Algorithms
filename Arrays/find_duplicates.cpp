#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        
        set<int> res;
        for (int i = 0; i < n; i++) {
            
            // only positive numbers;
            // if (arr[abs(arr[i])] < 0) res.insert(abs(arr[i]));
            // else arr[abs(arr[i])] *= -1;
            
            // 0 included
            if (arr[arr[i] % n] >= n) res.insert(arr[i] % n);
            else arr[arr[i] % n] += n;
        }
        if (res.empty()) return {-1};
        
        vector<int> v(res.begin(), res.end());
        return v;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    for (int e: obj.duplicates(arr, n)) cout << e << " ";
}