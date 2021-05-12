#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for (int i = 0; i < n; i++)
const int N = 1e7, M = N;
//=======================
int arr[N];

stack<int> solve() {
    int n, m;
    cin >> n;
    loop (i, n) cin >> arr[i];
    m = arr[n - 1];
    stack<int> leaders;
    leaders.push(m);
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= m) {
            leaders.push(arr[i]);
            m = arr[i];
        }
    }
    return leaders;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        stack<int> res = solve();
        while(!res.empty()) {
            cout << res.top() << " ";
            res.pop();
        }
        cout << endl;
    }
    return 0;
}