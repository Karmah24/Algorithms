#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector <int> dijkstra(int V, vector<pair<int, int>> adj[], int S) {

        vector<int> dis(V, INT_MAX);
        set<pair<int, int>> s;
        dis[S] = 0;
        s.insert({0, S});

        while(!s.empty()) {
            auto itr = s.begin();
            s.erase(itr);
            int u = (*itr).second;
            for (auto edge: adj[u]) {
                int v = edge.first;
                int edgeLen = edge.second;
                if (dis[v] > dis[u] + edgeLen) {
                    auto temp = s.find({dis[v], v});
                    if (temp != s.end()) {
                        s.erase(temp);
                    }
                    dis[v] = dis[u] + edgeLen;
                    s.insert({dis[v], v});
                }
            }
        }
        return dis;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int V, E, S;
    cin >> V >> E;
    vector<pair<int, int>> graph[V];
    while (E--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    cin >> S;
    Solution obj;
    for (int e: obj.dijkstra(V, graph, S)) cout << e << ' ';
}
