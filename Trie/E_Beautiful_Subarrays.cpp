#include <bits/stdc++.h>
using namespace std;
#define int long long
const int BITSZ = 30;
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
        for (int i = BITSZ; i >= 0; i--) {
            int x = (n >> i) & 1;
            u->cnt[x]++;
            if (!u->arr[x]) u->arr[x] = new Node();
            u = u->arr[x];
        }
    }
    int dfs(Node *u, int n, int i, int k) {

        if (!u || i < 0) return 0;
        int x = (n >> i) & 1, y = (k >> i) & 1;
        if (y == 0) {
            return dfs(u->arr[x], n, i - 1, k) + u->cnt[1 - x];
        }
        return dfs(u->arr[1 - x], n, i - 1, k);
    }
};

void testcase() {

    Trie trie;
    trie.insert(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int pfx_xor = 0, res = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pfx_xor ^= a[i];
        res += trie.dfs(trie.root, pfx_xor, BITSZ, k - 1);
        trie.insert(pfx_xor);
    }
    cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	//   freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	// cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
