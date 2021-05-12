#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0], v = flights[i][1], w = flights[i][2];
            adj[u].push_back({v, w});
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, K});
        
        while (!pq.empty()) {
            auto temp = pq.top();
            int dist = temp[0], u = temp[1], steps = temp[2];
            pq.pop();
            
            if (u == dst) return dist;
            if (steps < 0) continue;
            
            for (auto e: adj[u]) {
                int v = e.first, w = e.second;
                pq.push({dist + w, v, steps - 1});
            }
        }
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, m, src, dst, K;
    cin >> n >> m;
    vector<vector<int>> flights;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        flights.push_back({u, v, w});
    }
    cin >> src >> dst >> K;
    Solution obj;
    cout << obj.findCheapestPrice(n, flights, src, dst, K);
}
