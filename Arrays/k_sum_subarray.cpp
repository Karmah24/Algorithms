#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
#define ll long long
//=======================

class Solution{
    public:
    ll findSubarrayNum(vector<ll> arr, int n, int k) {

        unordered_map<ll, int> map;
        map[0] = 1;
        ll res = (ll)0, sum = (ll)0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            res += map[sum - k];
            map[sum]++;
        }
        return res;
    }
    
    vector<pair<int, int>> findAllSubarray(vector<ll> arr, int n) {

        unordered_map<ll, vector<int>> map;
        ll sum = (ll)0;
        vector<pair<int, int>> res;

        for (int i = 0; i < n; i++) {

            sum += arr[i];
            if (sum == 0) {
                res.push_back({0, i});
            }
            if (map.find(sum) != map.end()) {
                for (int v: map[sum]) {
                    res.push_back({v + 1, i});
                }
            }
            map[sum].push_back(i);
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    ll k;
    cin >> k;
    vector<ll> arr(n);
    loop (i, n) cin >> arr[i];
    Solution obj;
    // for (auto p: obj.findAllSubarray(arr, n)) {
    //     cout << p.first << " " << p.second << endl;
    // }
    cout << obj.findSubarrayNum(arr, n, k);
}
