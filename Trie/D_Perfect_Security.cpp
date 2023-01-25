#include <bits/stdc++.h>
using namespace std;
const int BITSZ = 30;
//================================================================

struct Node {
    Node *arr[2] = {nullptr};
    int cnt[2] = {0};
};

class Trie {
public:

    Node *root = nullptr;

    void insert(int n) {
        if (!root) root = new Node();
        Node *u = root;
        for (int i = BITSZ; i >= 0; i--) {
            int x = (n & (1 << i)) > 0;
            u->cnt[x]++;
            if (!u->arr[x]) u->arr[x] = new Node();
            u = u->arr[x];
        }
    }
    int dfs(Node *u, int n, int i) { // i = next bit
    
        if (!u->arr[0] && !u->arr[1]) return 0;
        int x = (n & (1 << i)) > 0;
        if (u->arr[x]) {
            int res = dfs(u->arr[x], n, i - 1);
            if (--u->cnt[x] == 0) u->arr[x] = nullptr;
            return res;
        }
        int res = dfs(u->arr[1 - x], n, i - 1) | (1 << i);
        if (--u->cnt[1 - x] == 0) u->arr[1 - x] = nullptr;
        return res;
    }
};
void testcase() {

    Trie trie;
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        trie.insert(b[i]);
    }
    for (auto &e: a) cout << trie.dfs(trie.root, e, BITSZ) << " ";
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
