#include<bits/stdc++.h>

using namespace std;
#define ll long long 
#define loop(i, n) for (int i = 0; i < n; i++)
//=======================

vector<long long> nextLarger(vector<long long> arr) {
    
    vector<ll> res(arr.size());
    stack<pair<ll, int>> stack;
    stack.push({arr[0], 0});

    for (int i = 1; i < arr.size(); i++) {
        while (!stack.empty() && arr[i] > stack.top().first) {
            res[stack.top().second] = arr[i];
            stack.pop();
        }
        stack.push({arr[i], i});
    }
    while (!stack.empty()) {
        res[stack.top().second] = -1;
        stack.pop();
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int T = 1;
    // cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> arr(n);
        loop (i, n) cin >> arr[i];
        for (ll e: nextLarger(arr)) cout << e << " ";
        cout << endl;
    }
    return 0;
}