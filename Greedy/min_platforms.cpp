#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPlatform1(int arr[], int dep[], int n) {
        
        sort(arr, arr + n);
        sort(dep, dep + n);

        int i = 1, j = 0;
        int platforms = 1, res = 1;
        while (i < n) {
            if (arr[i] <= dep[j]) {
                platforms++;
                res = max(platforms, res);
                i++;
            }
            else {
                platforms--;
                j++;
            }
        }
        return max(res, platforms);
    }
    int findPlatform(int arr[], int dep[], int n) {

        int platforms[2361] = {0};

        for (int i = 0; i < n; i++) {
            platforms[arr[i]]++;
            platforms[dep[i] + 1]--;
        }
        int res = 1;
        for (int i = 1; i < 2361; i++) {
            platforms[i] += platforms[i - 1];
            res = max(res, platforms[i]);
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
    int arr[n], dep[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) cin >> dep[i];
    Solution obj;
    cout << obj.findPlatform(arr, dep, n);
}