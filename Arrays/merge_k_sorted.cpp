#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
typedef pair<int, int>	pii;
typedef vector<int>		vi;
typedef vector<pii>		vpii;
typedef vector<vi>		vvi;
//=======================

class Solution {
public:
    vi solve(vvi arrs) {
        int k = arrs.size(), n = arrs[0].size();
        priority_queue<pii, vpii, greater<pii>> pq;
        int st[k];
        loop (i, k) {
            pq.push({arrs[i][0], i});
            st[i] = 0;
        }
        vi res;
        loop (i, n * k) {
            auto [num, idx] = pq.top();
            res.push_back(num);
            pq.pop();
            st[idx]++;
            if (st[idx] < n) pq.push({arrs[idx][st[idx]], idx});
        }
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n, k;
    cin >> k >> n;
    vvi arrs(k, vi(n));
    loop (i, k) loop (j, n) cin >> arrs[i][j];
    Solution obj;
    for (int e: obj.solve(arrs)) cout << e << ' ';
}
