#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
//================================================================

// deque solution
void testcase1() {

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    deque<int> q;
    int i = 0, j = 0;
    vector<int> res;
    while (j < k) {
        while (!q.empty() && a[q.front()] <= a[j]) q.pop_front();
        q.push_front(j);
        j++;
    }
    res.push_back(a[q.back()]);
    while (j < n) {
        if (!q.empty() && q.back() == i) q.pop_back();
        while (!q.empty() && a[q.front()] <= a[j]) q.pop_front();
        q.push_front(j);
        res.push_back(a[q.back()]);
        i++, j++;
    }
    for (auto &e: res) cout << e << " "; 
}

// dp
void testcase() {

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> dp(n);
    dp[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        dp[i] = dp[i + 1];
        if (a[i] > a[dp[i + 1]]) dp[i] = i;
    }
    int i = 0, j = 0, mx = 0;
    while (j < k) {
        int cur = j;
        if (dp[j] < i + k) cur = dp[j];
        if (a[cur] > a[mx]) mx = cur;
    }
    vector<int> res;
    res.push_back(a[mx]);
    while (j < n) {
        
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
