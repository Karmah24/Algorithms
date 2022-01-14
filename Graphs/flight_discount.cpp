#include <bits/stdc++.h>
using namespace std;

#define ll long long
//=======================

struct Package {

    ll amt;
    int city;
    bool disc;

    Package(ll amt, int city, bool disc) : amt(amt), city(city), disc(disc) {}
    bool operator <(const Package &other) const {
        return amt > other.amt;
    }
};

ll minCost(int n, vector<pair<int, int>> adj[], int src, int dest) {

    vector<ll> fullCost(n, LLONG_MAX);
    vector<ll> discCost(n, LLONG_MAX);
    priority_queue<Package> pq;
    fullCost[src] = discCost[src] = 0;
    pq.push(Package(0, src, true));

    while (!pq.empty()) {

        auto tp = pq.top();
        pq.pop();
        ll curr = tp.amt;
        int u = tp.city;
        bool disc = tp.disc;

        for (auto n: adj[u]) {
            auto [v, w] = n;
            if (disc) {
                if (fullCost[v] > curr + w) {
                    fullCost[v] = curr + w;
                    pq.push(Package(fullCost[v], v, true));
                }
                if (discCost[v] > curr + w / 2) {
                    discCost[v] = curr + w / 2;
                    pq.push(Package(discCost[v], v, false));
                }
            }
            else if (discCost[v] > curr + w) {
                discCost[v] = curr + w;
                pq.push(Package(discCost[v], v, false));
            }
        }
    }
    return discCost[dest];
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].push_back({v - 1, w});
    }
    cout << minCost(n, adj, 0, n - 1);
    return 0;
}