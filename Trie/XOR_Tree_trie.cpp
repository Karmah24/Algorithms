#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
#define ll long long
ll add(ll x, ll y) { return ((x % MOD) + (y % MOD)) % MOD; }
ll mul(ll x, ll y) { return ((x % MOD) * (y % MOD)) % MOD; }
ll mpow(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) res = mul(res, x);
        x = mul(x, x);
        n >>= 1;
    }
    return res;
}
ll inv(ll i) { return mpow(i, MOD - 2); }
ll sub(ll x, ll y) { return ((x % MOD) - (y % MOD) + MOD) % MOD; }
//================================================================

struct Node {
    Node* arr[2] = {nullptr};
    int cnt[2] = {0};
};

class Trie {
public:
    Node *root = nullptr;
    void insert(int n) {
		if (!root) root = new Node();
		Node *u = root;
		for (int i = 30; i >= 0; i--) {
			int x = (n >> i) & 1;
			u->cnt[x]++;
			if (!u->arr[x]) u->arr[x] = new Node();
			u = u->arr[x];
		}
	}
    void remove(int n) {
		Node *u = root;
		for (int i = 30; i >= 0 && u; i--) {
			int x = (n >> i) & 1;
			if (--u->cnt[x] == 0) u->arr[x] = nullptr;
			u = u->arr[x];
		}
    }
    int dfs(int n, int i) {
        int res = 0;
        Node *u = root;
        for (int i = 30; i >= 0; i--) {
            int x = (n >> i) & 1;
            if (u->arr[1 - x]) {
                u = u->arr[1 - x];
                res |= (1 << i);
            }
            else u = u->arr[x];
        }
        return res;
    }
};

int n;
vector<vector<int>> adj;
vector<int> a;

int dfs(int u, int p, Trie &trie, int xxor) {

    trie.insert(a[u]);
    xxor ^= a[u];
    int c = adj[u].size();
    if (p != -1) c--;
    int res = 0;
    if (c == 0) res = trie.dfs(xxor, 30);
    else {
        int inv_c = inv(c);
        for (auto &v: adj[u]) {
            if (v == p) continue;
            res += dfs(v, u, trie, xxor) * inv_c;
            res %= MOD;
        }
    }
    trie.remove(a[u]);
    return res;
}

void testcase() {

    cin >> n;
    
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    adj.assign(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Trie trie;
    cout << dfs(0, -1, trie, 0);
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		// freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
