#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int repeatedNumber(vector<int>& arr) {

        int slow = arr[0], fast = arr[arr[0]];

        while (fast != slow) {
            slow = arr[slow];
            fast = arr[arr[fast]];
        }
        slow = 0;

        while (slow != fast) {
            slow = arr[slow];
            fast = arr[fast];
        }
        return slow;
    }
    // int repeatedNumber(vector<int>& arr) {

    //     int i, n = arr.size();
    //     int x = ceil(sqrt(n - 1));

    //     int s[x] = {0};
    //     for (i = 0; i < n; i++) {
    //         s[(arr[i] - 1) / x]++;
    //     }
    //     i = 0;
    //     while (s[i] <= x) i++;

    //     int st = (x * i) + 1;

    //     unordered_set<int> m;
    //     for (int i = 0; i < n; i++) {

    //         if (arr[i] >= st && arr[i] < st + x) {
    //             if (m.find(arr[i]) != m.end()) return arr[i];
    //             m.insert(arr[i]);
    //         }
    //     }
    //     return -1;
    // }
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
    cout << obj.repeatedNumber(arr);
}