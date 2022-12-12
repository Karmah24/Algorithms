#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

void testcase() {

    vector<string> v = {"r", "", "m", "", "", "", "t"};
    for (int i = 0; i < v.size(); i++) {
        if (v[i].size() == 0) {
            v.erase(v.begin() + i);
        }
    }
    for (auto &e: v) cout << e << " ";
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
