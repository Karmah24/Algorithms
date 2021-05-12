#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int spanningTree(int V, vector<pair<int, int>> adj[]) {

        vector<int> cutEdge(V, INT_MAX);
        set<pair<int, int>> s;
        vector<bool> inMst(V, false);

        cutEdge[0] = 0;
        inMst[0] = true;
        for (auto edge: adj[0]) {
            int v = edge.first, w = edge.second;
            cutEdge[v] = w;
            s.insert({cutEdge[v], v});
        }
        int mstWeight = 0;

        while (!s.empty()) {
            auto itr = s.begin();
            s.erase(itr);
            int u = (*itr).second;
            inMst[u] = true;
            mstWeight += (*itr).first;

            for (auto edge: adj[u]) {
                if (inMst[edge.first]) continue;
                int v = edge.first, w = edge.second;
                if (cutEdge[v] > w) {
                    auto itr = s.find({cutEdge[v], v});
                    if (itr != s.end()) {
                        s.erase(itr);
                    }
                    cutEdge[v] = w;
                    s.insert({cutEdge[v], v});
                }
            }
        }
        return mstWeight;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int V, E;
    cin >> V >> E;
    vector<pair<int, int>> graph[V];
    while (E--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    Solution obj;
    cout << obj.spanningTree(V, graph);
}
