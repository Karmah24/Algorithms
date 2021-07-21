#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findOrder(string dict[], int n, int k) {
        
        unordered_set<int> adj[k];
        vector<int> inDegree(k, 0);

        for (int i = 0; i < n - 1; i++) {
            int x = 0, y = 0;
            while (x < dict[i].size() && y < dict[i + 1].size() && dict[i][x] == dict[i + 1][y]) {
                x++, y++;
            }
            if (x < dict[i].size() && y < dict[i + 1].size()) {
                int u = dict[i][x] - 'a', v = dict[i + 1][y] - 'a';
                if (adj[u].count(v)) continue;
                adj[u].insert(v);
                inDegree[v]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < k; i++) if (inDegree[i] == 0) q.push(i);
        string res = "";
        while (!q.empty()) {

            int u = q.front(); q.pop();
            res.push_back(u + 'a');

            for (int v: adj[u]) {
                if (--inDegree[v] == 0) q.push(v);
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    string dict[n];
    for (int i = 0; i < n; i++) cin >> dict[i];
    Solution obj;
    cout << obj.findOrder(dict, n, k);
}