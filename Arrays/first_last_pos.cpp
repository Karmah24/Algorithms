#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
typedef vector<int>		vi;
const int N = 3e5, M = N;
//=======================
int arr[N];

int bs(int lo, int hi, int k) {
    int st = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] >= k) {
            // if (arr[mid] == k)
                st = mid;
            hi = mid - 1;
        }
        else 
            lo = mid + 1;
    }
    return st;
}
void solve() {
    int n, x;
    cin >> n >> x;
    loop (i, n) cin >> arr[i];

    int st = bs(0, n - 1, x);
    int end = bs(st, n - 1, x + 1);
    cout << st << " " << end;

    // vi v(arr, arr + n);
    // auto st = lower_bound(all(v), x);
    // auto end = upper_bound(all(v), x);

    // if (!binary_search(all(v), x))
    //     cout << -1 << endl;
    // else 
    //     cout << st - v.begin() << " " << end - v.begin() - 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}