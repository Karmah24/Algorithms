#include<bits/stdc++.h>

using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//=======================


void solve() {
    int n;
    cin >> n;
    vpii intervals(n);
    vpii f_intv;
    loop (i, n) 
        cin >> intervals[i].first >> intervals[i].second;
    sort(intervals.begin(), intervals.end());
    int s = intervals[0].first, e = intervals[0].second;
    for (int i = 1; i < n; i++) {
        if (intervals[i].first <= e)
            e = max(e, intervals[i].second);
        else {
            f_intv.push_back({s, e});
            s = intervals[i].first, e = intervals[i].second;
        }
    }
    f_intv.push_back({s, e});
    for (auto y : f_intv) 
        cout << y.first << " " << y.second << " ";
    cout << endl; 
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}