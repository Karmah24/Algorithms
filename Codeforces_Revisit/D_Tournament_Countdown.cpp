#include <bits/stdc++.h>
using namespace std;
//================================================================

vector<int> a, winners;

int query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int res;
    cin >> res;
    return res;
}
void solve(int p) {

    if (p == 1) {
        cout << "! " << a[1] << endl;
        return;
    }
    if (p == 2) {
        int res = query(a[1], a[2]);
        if (res == 1) cout << "! " << a[1] << endl;
        else cout << "! " << a[2] << endl;
        return;
    }
    for (int i = 1; i <= p - 3; i += 4) {
        int res = query(a[i], a[i + 2]);
        if (res == 0) {
            int x = query(a[i + 1], a[i + 3]);
            if (x == 1) winners.push_back(a[i + 1]);
            else winners.push_back(a[i + 3]);
        }
        else if (res == 1) {
            int x = query(a[i], a[i + 3]);
            if (x == 1) winners.push_back(a[i]);
            else winners.push_back(a[i + 3]);
        }
        else {
            int x = query(a[i + 1], a[i + 2]);
            if (x == 1) winners.push_back(a[i + 1]);
            else winners.push_back(a[i + 2]);
        }
    }
    a.resize(winners.size() + 1);
    for (int i = 1; i <= winners.size(); i++) a[i] = winners[i - 1];
    winners.clear();
    solve(p / 4);
}
void testcase() {

	int n;
    cin >> n;
    int p = 1 << n;
    a.resize(p + 1);
    winners.clear();
    for (int i = 1; i <= p; i++) a[i] = i;
    
    solve(p);
}
signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	// #ifndef ONLINE_JUDGE
	//   freopen("input.txt", "r", stdin);
	//   freopen("output.txt", "w", stdout);
	// #endif
	int T = 1;
	cin >> T;
	while (T--) {
		testcase();
	}
	return 0;
}