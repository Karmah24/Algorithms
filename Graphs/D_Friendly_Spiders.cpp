#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
//================================================================

int n;
vector<set<int>> multiples;
vector<vector<int>> factors;

void factorize(int i, vector<int> &a) {

    int n = a[i];
    if (n % 2 == 0) {
        factors[i].push_back(2);
        multiples[2].insert(i);
    }
    while (n % 2 == 0) n /= 2;
    for (int f = 3; f * f <= n; f += 2) {
        if (n % f != 0) continue;
        factors[i].push_back(f);
        multiples[f].insert(i);
        while (n % f == 0) n /= f;
    }
    if (n > 1) {
        factors[i].push_back(n);
        multiples[n].insert(i);
    }
}

vector<int> bfs(int src, int dest) {

    queue<int> q;
    vector<int> prv(n, -1);
    q.push(src);
    for (auto &f: factors[src]) multiples[f].erase(src);
    while (q.size()) {

        int u = q.front(); q.pop();
        if (u == dest) break;
        set<int> vis;
        for (auto &f: factors[u]) {
            for (auto &v : multiples[f]) {
                vis.insert(v);
                prv[v] = u;
                q.push(v);
            }
        }
        for (auto &e: vis) {
            for (auto &f: factors[e]) multiples[f].erase(e); 
        }
    }
    if (prv[dest] == -1 && src != dest) return {};
    vector<int> path;
    while (dest != -1) {
        path.push_back(dest + 1);
        dest = prv[dest];
    }
    return path;
}

void testcase() {

    int src, dest;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> src >> dest;
    src--, dest--;

    multiples.assign(N, set<int>());
    factors.assign(n, vector<int>());
    for (int i = 0; i < n; i++) factorize(i, a);

    vector<int> path = bfs(src, dest);
    if (path.empty()) {
        cout << -1;
        return;
    }
    cout << path.size() << '\n';
    for (int i = path.size() - 1; i >= 0; i--) cout << path[i] << " ";
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		// freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	// cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
