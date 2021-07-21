#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& arr) {

        if (arr.size() == 1) return 0;
        if (arr[0] == 0) return -1;

        int max_reach = arr[0], steps = arr[0], jumps = 1;

        for (int i = 1; i < arr.size() - 1; i++) {

            max_reach = max(max_reach, i + arr[i]);
            if (--steps == 0) {
                jumps++;
                steps = max_reach - i;
                if (steps == 0) return -1;
            }
        }
        return jumps;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)  cin >> arr[i];
    Solution obj;
    cout << obj.jump(arr) << endl;
}