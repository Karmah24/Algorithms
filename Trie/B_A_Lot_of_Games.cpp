#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
//================================================================

struct Node {
    map<char, Node*> mp;
    bool win = 0, lose = 0;
};

Node *root = nullptr;

void insert(string s) {
    if (!root) root = new Node();
    Node *curr = root;
    for (auto &c: s) {
        if (!curr->mp[c]) curr->mp[c] = new Node();
        curr = curr->mp[c];
    }
}

void dfs(Node *u) {
    if (u->mp.empty()) {
        u->win = 0;
        u->lose = 1;
        return;
    }
    for (auto &[k, v]: u->mp) {
        dfs(v);
        u->win |= !v->win;
        u->lose |= !v->lose;
    }
}

void testcase() {

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        insert(s);
    }
    dfs(root);
    if (!root->win) cout << "Second";
    else if (root->lose) cout << "First";
    else cout << (k & 1 ? "First" : "Second");
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
