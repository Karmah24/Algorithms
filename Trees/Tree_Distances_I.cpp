// for each node determine the maximum distance from another node.

// Solution 1
// 2 possibilities for every node
// first - farthest node lies in its subtree
// second - path to farthest node goes through the parent node.
// in the second case there are 3 possible paths from par
// first - path in prefix subtrees [0, i - 1], i = current child node
// second - path in suffix subtrees [i + 1, k] k = total children
// third - path through its par (grand par of current node)
// best of these 3 will be the partial res for node i;

// Solution 2
// farthest node from a given node can only be 1 of the 2 endpoints of the diameter

#include <bits/stdc++.h>
using namespace std;
//================================================================

int n;
vector<vector<int>> adj;
vector<int> par, height, res;

void dfs1(int u) {

    for (auto &v: adj[u]) {

        if (v == par[u]) continue;
        par[v] = u;
        dfs1(v);
        height[u] = max(height[u], height[v] + 1);
    }
}

void dfs2(int u, int partial_res) {

    vector<int> pfx_max, sfx_max;
    for (auto &v: adj[u]) {

        if (v == par[u]) continue;
        pfx_max.push_back(height[v]);
        sfx_max.push_back(height[v]);
    }
    int k = pfx_max.size(); // # children
    for (int i = 1; i < k; i++) {

        pfx_max[i] = max(pfx_max[i], pfx_max[i - 1]);
    }
    for (int i = k - 2; i >= 0; i--) {

        sfx_max[i] = max(sfx_max[i], sfx_max[i + 1]);
    }
    // evaluate partial res for children
    int i = 0;
    for (auto &v: adj[u])  {

        if (v == par[u]) continue;
        int op1 = 1 + (i == 0 ? -1 : pfx_max[i - 1]);
        int op2 = 1 + (i == k - 1 ? -1 : sfx_max[i + 1]);
        int op3 = 1 + partial_res;
        int best = max({op1, op2, op3});

        i++;
        dfs2(v, best);
    }
    // evaluate res for u
    res[u] = 1 + max(k == 0 ? -1 : pfx_max.back(),  partial_res);
}

void solve1() {

    cin >> n;

    adj.assign(n, vector<int>());
    par.assign(n, -1);
    height.assign(n, 0);
    for (int i = 0; i < n - 1; i++) {
       int u, v;
       cin >> u >> v;
       u--, v--;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }

    dfs1(0);
    res.assign(n, 0);
    dfs2(0, -1);

    for (auto &e: res) cout << e << " ";
}

void dfs3(int u, vector<int> &dep) {

    for (auto &v: adj[u]) {

        if (v == par[u]) continue;
        par[v] = u;
        dep[v] = dep[u] + 1;
        dfs3(v, dep);
    }
}
void solve2() {

    cin >> n;
    
    adj.assign(n, vector<int>());
    par.assign(n, -1);
    for (int i = 0; i < n - 1; i++) {
       int u, v;
       cin >> u >> v;
       u--, v--;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
    vector<int> dep1(n, 0);
    dfs3(0, dep1);
    int d1 = max_element(dep1.begin(), dep1.end()) - dep1.begin();
    par.assign(n, -1);
    dep1.assign(n, 0);
    dfs3(d1, dep1);
    int d2 = max_element(dep1.begin(), dep1.end()) - dep1.begin();
    par.assign(n, -1);
    vector<int> dep2(n, 0);
    dfs3(d2, dep2);

    for (int i = 0; i < n; i++) {

        cout << max(dep1[i], dep2[i]) << " ";
    }
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	  freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	// cin >> T;
	while (T--) {
		solve2();
		cout << '\n';
	}
	return 0;
}
