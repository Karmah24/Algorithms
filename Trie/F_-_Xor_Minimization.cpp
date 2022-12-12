#include <bits/stdc++.h>
using namespace std;
//================================================================

struct Node {
	Node* arr[2] = {nullptr};
};

class Trie {
public:
	Node *root = nullptr;

	void insert(int n) {
		if (!root) root = new Node();
		Node *curr = root;
		for (int i = 30; i >= 0; i--) {
			int x = (n & (1 << i)) > 0;
			if (!curr->arr[x]) curr->arr[x] = new Node();
			curr = curr->arr[x];
		}
	}
};

int dfs(Node *node, int x) {

	if (x < 0) return 0;
	if (!node->arr[0]) return dfs(node->arr[1], x - 1);
	if (!node->arr[1]) return dfs(node->arr[0], x - 1);

	return min(dfs(node->arr[0], x - 1), dfs(node->arr[1], x - 1)) | (1 << x);
}

void testcase() {

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	a.erase(unique(a.begin(), a.end()), a.end());
	Trie trie;
	for (auto &e: a) trie.insert(e);

	cout << dfs(trie.root, 30);
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
