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
typedef vector<pl>		vppl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
const int mod = int(1e9 + 7);
const int N = 3e5, M = N;
//=======================
int arr[N];

int solve(int n) {

    int x = floor(log2(n));
    return (1 << x) - 1;
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
        cout << solve(n) << endl;
    }
    return 0;
}