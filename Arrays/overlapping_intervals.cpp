#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//=======================


vpii merge(vpii intervals, int n) {
    vpii res;
    sort(intervals.begin(), intervals.end());
    int s = intervals[0].first, e = intervals[0].second;

    for (int i = 1; i < n; i++) {

        if (intervals[i].first <= e)
            e = max(e, intervals[i].second);
        else {
            res.push_back({s, e});
            s = intervals[i].first, e = intervals[i].second;
        }
    }
    res.push_back({s, e});
    
    return res;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vpii intervals(n);
    loop (i, n) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    for (auto p: merge(intervals, n)) {
        cout << p.first << " " << p.second << " ";
    }
}