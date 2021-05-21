#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define PI 3.1416
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
const int mod = int(1e9 + 7);
const int N = 3e5, M = N;
//=======================

ll solve(vi arr, int n) {

    unordered_map<int, pl> m;

    ll res = 0;
    loop (i, n) {
    
        if (m.count(arr[i]) == 0) m[arr[i]] = {1, 0};
        else {
            m[arr[i]].second = m[arr[i]].second + m[arr[i]].first;
            m[arr[i]].first = m[arr[i]].first + 1;
            res += m[arr[i]].second;
        }
        loop (j, i) {
            res += m[arr[j]].second;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi arr(n);
        loop (i, n) cin >> arr[i];
        cout << solve(arr, n) << endl;

    }
    return 0;
}