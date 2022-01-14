#include <bits/stdc++.h>
using namespace std;

int timer;
vector<vector<int>> adj;
vector<int> inTime, outTime;

void eulerTour(int u, int par) {
    inTime[u] = timer++;
    for (int v: adj[u]) {
        if (v != par) eulerTour(v, u);
    }
    outTime[u] = timer++;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, queries;
    cin >> n;
    adj = vector<vector<int>>(n);
    inTime = outTime = vector<int>(n);
    timer = 0;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    eulerTour(0, -1);
    cin >> queries;
    while (queries--) {
        int dir, x, y;
        cin >> dir >> x >> y;
        x--, y--;
        if (dir == 0) {
            if (inTime[x] < inTime[y] && outTime[x] > outTime[y]) cout << "YES\n";
            else cout << "NO\n";
        }
        else {
            if (inTime[x] > inTime[y] && outTime[x] < outTime[y]) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}