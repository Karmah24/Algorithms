#include <bits/stdc++.h>
using namespace std;

class Solution1 {
    int dp[1001][1001];
    bool vis[1001];
    vector<vector<pair<int, int>>> graph;
    int n;

    int solve(int u, int time, vector<int> &toll) {

        if (time < 0) return INT_MAX;
        if (u == n - 1) return toll[u];
        if (dp[u][time] != -1) return dp[u][time];
        vis[u] = 1;

        dp[u][time] = INT_MAX;
        for (auto n: graph[u]) {

            // if (vis[n.first]) continue;
            int res = solve(n.first, time - n.second, toll);
            if (res != INT_MAX) dp[u][time] = min(dp[u][time], res + toll[u]);
        }
        vis[u] = 0;
        return dp[u][time];
    }

public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& toll) {

        memset(vis, 0, sizeof(vis));
        memset(dp, -1, sizeof(dp));
        n = toll.size();
        graph = vector<vector<pair<int, int>>>(n);

        for (auto &v: edges) {
            if (v[0] > v[1]) swap(v[0], v[1]);
        }
        sort(edges.begin(), edges.end());

        for (int i = 0; i < edges.size(); i++) {

            auto v = edges[i];
            if (i != 0 && v[0] == edges[i - 1][0] && v[1] == edges[i - 1][1]) continue;
            graph[v[0]].push_back({v[1], v[2]});
            graph[v[1]].push_back({v[0], v[2]});
        }
        int res = solve(0, maxTime, toll);
        if (res == INT_MAX) return -1;
        return res;
    }
};

class Solution {
    int n;
    vector<vector<pair<int, int>>> graph;

    int solve(int src, int maxTime, vector<int> &toll) {

        int cost[n], time[n];
        for (int i = 0; i < n; i++) cost[i] = time[i] = INT_MAX;
        cost[src] = time[src] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({cost[src], time[src], src});

        while (!pq.empty()) {

            int c = pq.top()[0], t = pq.top()[1], u = pq.top()[2];
            pq.pop();

            for (auto edge: graph[u]) {

                int v = edge.first, len = edge.second;

                if (t + len > maxTime) continue;

                if (cost[v] > c + toll[u]) {
                    cost[v] = c + toll[u];
                    time[v] = t + len;
                    pq.push({cost[v], time[v], v});
                }
                else if (time[v] > t + len) {
                    time[v] = t + len;
                    pq.push({c + toll[u], time[v], v});
                }
            }
        }
        return cost[n - 1] == INT_MAX ? -1 : cost[n - 1] + toll[n - 1];
    }
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& toll) {

        n = toll.size();
        graph = vector<vector<pair<int, int>>>(n);
        for (auto v: edges) {
            graph[v[0]].push_back({v[1], v[2]});
            graph[v[1]].push_back({v[0], v[2]});
        }

        return solve(0, maxTime, toll);
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, m, x;
    cin >> n >> m >> x;
    vector<int> toll(n);
    for (int i = 0; i < n; i++) cin >> toll[i];
    vector<vector<int>> edges(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    Solution obj;
    cout << obj.minCost(x, edges, toll);
}