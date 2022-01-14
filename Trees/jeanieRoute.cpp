#include <bits/stdc++.h>
using namespace std;

class Graph {

public:
    vector<vector<pair<int, int>>> adj;
    int V;
    Graph(int n) : adj(n), V(n) {

        for (int i = 0; i < V - 1; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }   
    }

    void prune(unordered_set<int>& s) {
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (s.find(i) == s.end() && adj[i].size() == 1) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            int v = adj[u][0].first;
            adj[u].clear();
            for (int i = 0; i < adj[v].size(); i++) {
                if (adj[v][i].first == u) {
                    adj[v].erase(adj[v].begin() + i);
                    break;
                }
            }
            if (s.find(v) == s.end() && adj[v].size() == 1) q.push(v);
        }
    }

    vector<int> bfs(int s) {
        vector<bool> vis(V, false);
        queue<int> q;
        q.push(s);
        int farthest = s, maxDis = 0, totWeight = 0;
        int dis[V];
        dis[s] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = true;
            for (auto edge: adj[u]) {
                int v = edge.first, w = edge.second;
                if (vis[v]) continue;
                q.push(v);
                dis[v] = dis[u] + w;
                if (dis[v] > maxDis) {
                    maxDis = dis[v];
                    farthest = v;
                }
                totWeight += w;
            }
        }
        return {farthest, maxDis, totWeight};
    }
};

class Solution {
public:
    int solve(Graph G, vector<int> letterDes) {
        unordered_set<int> s;
        for (int e: letterDes) s.insert(e - 1);
        G.prune(s);
        int i = 0;
        while (G.adj[i].empty()) i++;
        vector<int> res = G.bfs(i);
        res = G.bfs(res[0]);

        return (2 * res[2]) - res[1];
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int V, K;
    cin >> V >> K;
    vector<int> letterDes;
    while (K--) {
        int t;
        cin >> t;
        letterDes.push_back(t);
    }
    Graph G(V);
    Solution obj;
    cout << obj.solve(G, letterDes);
}
