#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
//================================================================

void testcase() {

    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> pos(n + 1);
    for (int i = 1; i < n + 1; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    vector<int> p(n + 1), q(n + 1);
    vector<int> free_p, free_q;
    bool ok = 1;
    for (int i = n; i >= 1 && ok; i--) {
        int cnt = pos[i].size();
        if (cnt > 2) ok = 0;
        else if (cnt == 0) {
            if (free_p.empty() || free_q.empty()) ok = 0;
            else {
                p[free_p.back()] = i;
                q[free_q.back()] = i;
                free_p.pop_back(), free_q.pop_back();
            }
        }
        else if (cnt == 1) {
            p[pos[i][0]] = q[pos[i][0]] = i;
        }
        else {
            p[pos[i][0]] = q[pos[i][1]] = i;
            free_p.push_back(pos[i][1]);
            free_q.push_back(pos[i][0]);
        }
    }
    if (!ok) cout << "NO";
    else {
        cout << "YES\n";
        for (int i = 1; i < n + 1; i++) cout << p[i] << " ";
        cout << '\n';
        for (int i = 1; i < n + 1; i++) cout << q[i] << " ";
    }
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
