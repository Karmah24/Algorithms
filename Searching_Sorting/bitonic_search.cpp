#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& arr, int k) {
    
        int l = 0, r = arr.size() - 1;
        int ip;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                ip = mid;
                break;
            }
            if (arr[mid] > arr[mid - 1]) l = mid + 1;
            else r = mid - 1;
        }
        cout << ip << endl;
        if (k == arr[ip]) return ip;
        if (k > arr[ip]) return -1;
        
        l = 0, r = ip - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (arr[mid] == k) return mid;
            if (arr[mid] > k) r = mid - 1;
            else l = mid + 1;
        }
        
        l = ip + 1, r = arr.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (arr[mid] == k) return mid;
            if (arr[mid] > k) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    cout << obj.solve(arr, k);
}