#include <bits/stdc++.h>
using namespace std;
//================================================================

void testcase() {

    int n;
    cin >> n;
    vector<int> b(n + 1);
    int k = 0;
    for (int i = 1; i < n + 1; i++) {
        cin >> b[i];
        if (b[i] > i) k = i;
    }
    vector<vector<int>> adj(n + 1, vector<int>());
    vector<int> in_deg(n + 1, 0);
    for (int i = 1; i < n + 1; i++) {
        if (0 < b[i] && b[i] < n + 1) {
            adj[b[i]].push_back(i);
            in_deg[i]++;
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i < n + 1; i++) {
        if (in_deg[i] == 0) pq.push({adj[i].size(), i});
    }
    cout << k << '\n';
    while (!pq.empty()) {

        auto[_, u] = pq.top(); pq.pop();
        cout << u << " ";
        for (auto &v: adj[u]) if (--in_deg[v] == 0) pq.push({adj[v].size(), v});
    }
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	  freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
