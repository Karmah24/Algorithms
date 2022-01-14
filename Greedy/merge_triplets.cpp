#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        bool res[3];
        memset(res, false, sizeof(res));
        for (auto &t: triplets) {
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) {
                continue;
            }
            for (int i = 0; i < 3; i++) {
                if (t[i] == target[i]) res[i] = 1;
            }
        }
        return res[0] && res[1] && res[2];
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<vector<int>> triplets(n, vector<int>(3));
    vector<int> target(3);
    for (int i = 0; i < n; i++) {
        cin >> triplets[i][0];
        cin >> triplets[i][1];
        cin >> triplets[i][2];
    }
    cin >> target[0];
    cin >> target[1];
    cin >> target[2];
    Solution obj;
    cout << obj.mergeTriplets(triplets, target);
}