#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 31625;
//================================================================

vector<int> primes;
vector<bool> isPrime(N, 1);

void sieve() {

	for (int p = 2; p * p < N; p++) {
		if (!isPrime[p]) continue;
		for (int i = p * p; i < N; i += p) isPrime[i] = 0;
	}
	for (int i = 2; i < N; i++) if (isPrime[i]) primes.push_back(i);
}

void testcase() {

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	bool ok = 0;
	for (auto &p: primes) {
		int cnt = 0;
		for (auto &e: a) {

			if (e % p == 0) cnt++;
			if (cnt > 1) {
				ok = 1;
				break;
			}
			while (e % p == 0) e /= p;
		}
	}
	if (ok) {
		cout << "YES";
		return;
	}
	set<int> st;
	for (auto &e: a) {
		if (e == 1) continue;
		if (st.count(e)) {
			ok = 1;
			break;
		}
		st.insert(e);
	}
	cout << (ok ? "YES" : "NO");
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	//   freopen("output.txt", "w", stdout);
	#endif

	sieve();
	int T = 1;
	cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
