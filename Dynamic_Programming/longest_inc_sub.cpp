#include<bits/stdc++.h>

using namespace std;
const int N = 1000;
//=======================
int arr[N];

int solve(int n) {
    int res[n];
    for (int i = 0; i < n; i++) res[i] = 1;
    int max = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && res[i] <= res[j]) {
                res[i] = res[j] + 1;
                max = std::max(max, res[i]);
            }
        }
    }
    return max;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];
        cout << solve(n) << endl;
    }
    return 0;
}