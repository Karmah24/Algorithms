#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n;
    vector<vector<int>> configs;
    vector<pair<int, int>> queens;

    void getConfigs(int i) {
        if (i == n) {
            vector<int> config;
            for (auto p: queens) config.push_back(p.second + 1);
            configs.push_back(config);
            return;
        }
        for (int j = 0; j < n; j++) {
            bool flag = true;
            for (auto p: queens) {
                if (p.second == j || ((double)abs(p.first - i) / abs(p.second - j)) == 1) {
                    flag = false;
                    break;
                };
            }
            if (!flag) continue;
            queens.push_back({i, j});
            getConfigs(i + 1);
            queens.pop_back();
        }
    }
public:
    vector<vector<int>> nQueen(int a) {
        n = a;
        configs.clear();
        getConfigs(0);
        return configs;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    Solution obj;
    for (auto v: obj.nQueen(n)) {
        for (int e: v) cout << e << " ";
        cout << endl;
    }
}