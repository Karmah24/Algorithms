#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int u, stack<int> &st, vector<bool> &vis, vector<int> adj[]) {
        
        vis[u] = 1;
        for (int v: adj[u]) {
            if (!vis[v]) dfs(v, st, vis, adj);
        }
        st.push(u);
    }
    void dfs(int u, vector<bool> &vis, vector<int> adj[]) {
        vis[u] = 1;
        for (int v: adj[u]) {
            if (!vis[v]) dfs(v, vis, adj);
        }
    }
public:
    int kosaraju(int V, vector<int> adj[]) {
        
        stack<int> st;
        vector<bool> vis(V, 0);
        for (int u = 0; u < V; u++) {
            if (!vis[u]) dfs(u, st, vis, adj);
        }
        vector<int> transpose[V];
        for (int u = 0; u < V; u++) {
            for (int v: adj[u]) transpose[v].push_back(u);
        }
        vis = vector<bool>(V, 0);
        int res = 0;
        while (!st.empty()) {
            int u = st.top();
            st.pop();
            if (vis[u]) continue;
            res++;
            dfs(u, vis, transpose);
        }
        return res;
    }
};