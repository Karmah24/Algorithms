#include <bits/stdc++.h>
using namespace std;

struct vertex {
    int pos, rank = 0;
    vertex* par = nullptr;
    vertex(int x): pos(x) {}
};

class Solution {

    void _union(vertex* root1, vertex* root2) {
        if (root1->rank >= root2->rank) {
            root2->par = root1;
            if (root1->rank == root2->rank) root1->rank++;
        }
        else root1->par = root2;
    }
    vertex* find(vertex* v) {
        if (!v->par) return v;
        v->par = find(v->par);
        return v->par;
    }
public:
    int spanningTree(int V, vector<pair<int, int>> adj[]) {

        vector<vertex*> vertices;
        for (int i = 0; i < V; i++) vertices.push_back(new vertex(i));
        set<pair<int, pair<vertex*, vertex*>>> edges;

        for (int i = 0; i < V; i++) {
            for (auto e: adj[i]) {
                int v = e.first, w = e.second;
                if (edges.find({w, {vertices[v], vertices[i]}}) == edges.end()) {
                    edges.insert({w, {vertices[i], vertices[v]}});
                }
            }
        }
        int mstWeight = 0;
        for (auto edge: edges) {
            vertex *root1 = find(edge.second.first), *root2 = find(edge.second.second);
            if (root1 != root2) {
                _union(root1, root2);
                mstWeight += edge.first;
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
