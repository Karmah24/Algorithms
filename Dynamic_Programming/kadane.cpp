#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll maxSubarraySum(int arr[], int n){
        
        ll res = arr[0], m = arr[0];
        
        for (int i = 1; i < n; i++) {
            
            m = max((ll)arr[i], m + arr[i]);
            res = max(m, res);
        }    
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    cout << obj.maxSubarraySum(arr, n);
    return 0;
}