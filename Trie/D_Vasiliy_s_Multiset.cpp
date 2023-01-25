#include <bits/stdc++.h>
using namespace std;
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
			int x = (n & (1 << i)) > 0;
			u->cnt[x]++;
			if (!u->arr[x]) u->arr[x] = new Node();
			u = u->arr[x];
		}
	}
	void remove(int n) {

		Node *u = root;
		for (int i = 30; i >= 0; i--) {
			int x = (n & (1 << i)) > 0;
			if (--u->cnt[x] == 0) {
				u->arr[x] = nullptr;
				break;
			}
			u = u->arr[x];
		}
	}
	int dfs(Node *u, int n, int i) {

		if (!u->arr[0] && !u->arr[1]) return 0;
		int x = (n & (1 << i)) > 0;
		if (u->arr[1 - x]) return dfs(u->arr[1 - x], n, i - 1) | (1 << i);
		return dfs(u->arr[x], n, i - 1);
	}
};

void testcase() {

	Trie trie;
	trie.insert(0);
	int q;
	cin >> q;
	map<int, int> cnt;
	while (q--) {
		char op;
		int n;
		cin >> op >> n;
		if (op == '+') {
			if (cnt[n] == 0) trie.insert(n);
			cnt[n]++;
		}
		else if (op == '-') {
			if (cnt[n] == 1) trie.remove(n);
			cnt[n]--;
		}
		else cout << trie.dfs(trie.root, n, 30) << '\n';
	}
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
