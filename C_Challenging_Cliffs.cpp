#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> solve() {
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    if (n < 5) {

    }
    sort(arr.begin(), arr.end());

    int minDis = INT_MAX;
    set<pair<int, int>> st;
    for (int i = 0; i < n - 1; i++) {
        if (minDis < arr[i + 1] - arr[i]) continue;
        if (minDis > arr[i + 1] - arr[i]) {
            minDis = arr[i + 1] - arr[i];
            if (!st.empty()) st.clear();
        }
        st.insert({i, i + 1});
    }
    pair<int, int> l = *st.begin();
    if (arr[l.first] == arr[0]) {
        int x = arr[l.second];
        arr.erase(arr.begin() + l.second);
        arr.push_back(x);
        return arr;
    }
    pair<int, int> r = *prev(st.end());
    int x = arr[r.first], y = arr[r.second];
    arr.erase(arr.begin() + r.first);
    arr.erase(arr.begin() + r.second - 1);
    arr.push_back(y);
    vector<int> res = {x};
    res.insert(res.end(), arr.begin(), arr.end());
    return res;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed);

    int T = 1;
    cin >> T;
    while (T--) {
        for (int e: solve()) cout << e << " ";
        cout << '\n';
    }
    return 0;
}