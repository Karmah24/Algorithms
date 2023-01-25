#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
//================================================================

void testcase() {

    int n;
    string s;
    cin >> n >> s;

    vector<pair<int, int>> cnt(26);
    vector<vector<int>> pos(26);
    for (int i = 0; i < 26; i++) cnt[i] = {0, i};
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a'].first++;
        pos[s[i] - 'a'].push_back(i);
    }
    sort(cnt.rbegin(), cnt.rend());

    int res = n;
    vector<int> inc(26, 0), dec(26, 0);
    for (int i = 1; i < n + 1; i++) {
        if (n % i != 0 || n / i > 26) continue;
        int k = n / i;
        vector<int> temp_inc(26, 0), temp_dec(26, 0);
        for (int j = 0; j < k; j++) {
            int diff = cnt[j].first - i;
            if (diff < 0) temp_inc[cnt[j].second] += -diff;
            else temp_dec[cnt[j].second] += diff;
        }
        for (int j = k; j < 26; j++) temp_dec[cnt[j].second] += cnt[j].first;
        int ops = accumulate(temp_dec.begin(), temp_dec.end(), 0LL);
        if (ops < res) {
            res = ops;
            inc = temp_inc, dec = temp_dec;
        }
    }
    cout << res << '\n';
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26 && dec[i]; j++) {
            while (dec[i] && inc[j]) {
                s[pos[i].back()] = 'a' + j;
                dec[i]--, inc[j]--;
                pos[i].pop_back();
            }
        }
    }
    cout << s;
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
