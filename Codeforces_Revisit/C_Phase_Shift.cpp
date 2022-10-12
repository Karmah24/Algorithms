// All alphabets (a - z) are placed in a circle
// a string is encrypted by replacing each letter with the next in the circle
// given an ecrypted string (s) find the lexicographically smallest original string.

// for each letter c in s there has to be a unique letter p such that p -> c is a part of the circle
// similarly p can preceed only one letter c
// no cycle of length less than 26 can be formed.

#include <bits/stdc++.h>
using namespace std;
//================================================================

class DSU {
public:
    vector<int> par, rank;
    DSU(int n): par(n), rank(n, 1) {
        for (int i = 0; i < n; i++) par[i] = i;
    }
    int find(int x) {
        return x == par[x] ? x : x = find(par[x]);
    }
    int merge(int x, int y) {
        if ((x = find(x)) == (y = find(y))) return x;
        par[y] = x;
        rank[x] += rank[y];
        return x;
    }
};

void testcase() {

    int n;
    string s;
    cin >> n >> s;

    string res = ""; // original string
    vector<int> in(26, -1); // p -> c; in[c] = p
    vector<int> out(26, -1); // p -> c; out[p] = c
    DSU dsu(26);

    auto is_valid = [&](int p, int c) -> int {

        if (in[c] != -1 || out[p] != -1) return false;
        p = dsu.find(p), c = dsu.find(c);
        if (p == c && dsu.rank[p] < 26) return false;
        return true;
    };

    for (int i = 0; i < n; i++) {

        int c = s[i] - 'a';
        if (in[c] == -1) {

            for (int p = 0; p < 26; p++) {

                if (is_valid(p, c)) {

                    in[c] = p;
                    out[p] = c;
                    dsu.merge(p, c);
                    break;
                }
            }
        }
        res.push_back(in[c] + 'a');
    }
    cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	  freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
