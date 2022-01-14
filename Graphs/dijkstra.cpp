#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<int> dijkstraSet(int V, vector<pair<int, int>> adj[], int src) {

        vector<int> dis(V, INT_MAX);
        set<pair<int, int>> s;
        dis[src] = 0;
        s.insert({0, src});

        while(!s.empty()) {

            auto itr = s.begin();
            int u = (*itr).second;  
            s.erase(itr);

            for (auto edge: adj[u]) {

                int v = edge.first, edgeLen = edge.second;

                if (dis[v] <= dis[u] + edgeLen) continue;

                auto temp = s.find({dis[v], v});
                if (temp != s.end()) s.erase(temp);

                dis[v] = dis[u] + edgeLen;
                s.insert({dis[v], v});
            }
        }
        return dis;
    }
    vector<ll> dijkstra(int V, vector<pair<int, int>> adj[], int src) {

        vector<ll> dis(V, LLONG_MAX);
        priority_queue<pair<ll, ll>> pq;
        vector<bool> vis(dis.size(), false);
        
        dis[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {

            auto [d, u] = pq.top();
            pq.pop();
            if (vis[u]) continue;
            vis[u] = true;

            for (auto n: adj[u]) {
                auto [v, w] = n;
                if (dis[v] > -d + w) {
                    dis[v] = -d + w;
                    pq.push({-dis[v], v});
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

    int V, E, src;
    cin >> V >> E;
    vector<pair<int, int>> graph[V];
    while (E--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    cin >> src;
    Solution obj;
    for (int e: obj.dijkstra(V, graph, src)) cout << e << ' ';
}
