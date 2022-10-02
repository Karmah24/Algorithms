#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
//================================================================

void testcase() {

    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {

        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a.begin(), a.end());

    int i = 1, extra = 0, sz = n;
    for (; i < n + 1; i++) {

        if (cnt[i]) {

            cnt[i]--;
            sz--;
            extra += cnt[i];
            continue;
        }
        if (extra >= 2) {
            
            extra -= 2;
            sz -= 2;
        }
        else if (extra == 1 && sz - extra >= 1) {

            cnt[a.back()]--;
            a.pop_back();
            extra--;
            sz -= 2;
        }
        else if (sz >= 2){
            
            cnt[a.back()]--;
            a.pop_back();
            cnt[a.back()]--;
            a.pop_back();
            sz -= 2;
        }
        else break;
    }
    cout << i - 1;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	  freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	// cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
