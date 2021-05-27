#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(int arr1[], int arr2[], int n, int m) {

        int i = 0, j = 0, k = n - 1;
        while (i <= k && j < m) {
            if (arr1[i] <= arr2[j]) i++;
            else {
                swap(arr2[j], arr1[k]);
                j++;
                k--;
            }
        }
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    int arr1[n], arr2[m];
    for (int i = 0; i < n; i++) cin >> arr1[i];
    for (int i = 0; i < m; i++)  cin >> arr2[i];
    Solution obj;
    obj.merge(arr1, arr2, n, m);
    for (int i = 0; i < n; i++)  cout << arr1[i] << ' ';
    for (int i = 0; i < m; i++)  cout << arr2[i] << ' ';
}
