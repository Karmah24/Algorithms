#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> res;
    int timer;
    vector<int> low;

    void dfs(int u, stack<int> &st, vector<bool> &inSt, vector<int> adj[]) {

        st.push(u);
        inSt[u] = true;
        int disc = low[u] = timer++;
        for (int v: adj[u]) {

            if (low[v] != -1 && !inSt[v]) continue;
            if (low[v] == -1) dfs(v, st, inSt, adj);
            low[u] = min(low[u], low[v]);
        }
        if (low[u] != disc) return;
        vector<int> curr;
        while (st.top() != u) {
            curr.push_back(st.top());
            inSt[st.top()] = false;
            st.pop();
        }
        curr.push_back(u);
        inSt[u] = false;
        st.pop();
        sort(curr.begin(), curr.end());
        res.push_back(curr);
    }
public:
    vector<vector<int>> tarjans(int V, vector<int> adj[]) {

        res.clear();
        timer = 0;
        low = vector<int>(V, -1);
        stack<int> st;
        vector<bool> inSt(V, false);

        for (int u = 0; u < V; u++) {
            if (low[u] == -1) dfs(u, st, inSt, adj);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    while (E--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    Solution obj;
    for (auto ssc: obj.tarjans(V, adj)) {
        for (int e: ssc) cout << e << " ";
        cout << '\n';
    }
}