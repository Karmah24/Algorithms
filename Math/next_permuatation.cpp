#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string nextPermutation(string arr) {
        
        int n = arr.size();
        int i = n - 2;

        while (i >= 0 && arr[i] >= arr[i + 1]) i--;
        if (i < 0) return arr;
        int j = n - 1;
        while (j > i) {

            if (arr[i] < arr[j]) {
                swap(arr[i], arr[j]);
                reverse(arr.begin() + i + 1, arr.end());
                break;
            }
            j--;
        }
        return arr;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string str;
    cin >> str;
    Solution obj;
    cout << obj.nextPermutation(str);
}