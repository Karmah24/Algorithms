#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> soldiers;
    for (int i = 0; i < N; i++) soldiers.push_back(i + 1);

    while (soldiers.size() > 1) {

        vector<int> survivors;
        int n = soldiers.size();
        for (int i = 0; i < n; i++) {
            if (i % 2 != 0) cout << soldiers[i] << " ";
            else survivors.push_back(soldiers[i]);
        }
        soldiers.clear();
        if (n % 2 != 0) {
            soldiers.push_back(survivors.back());
            survivors.pop_back();
        }
        soldiers.insert(soldiers.end(), survivors.begin(), survivors.end());
    }
    cout << soldiers[0];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}