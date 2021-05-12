#include <bits/stdc++.h>
using namespace std;

#define fori(i, n) for (int i = 0; i < n; i++)
typedef pair<int, int>	pii;
typedef vector<int>		vi;
typedef vector<vi>		vvi;
//=======================

class Solution {
public:
    vvi fourSum(vector<int>& arr, int target) {

        int n = arr.size();
        vvi res;
        unordered_map<int, set<pii>> map;
        
        for (int i = 1; i < n - 1; i++) {

            for (int j = i + 1; j < n; j++) {

                int rem = target - arr[i] - arr[j];
                if (map[rem].size() > 0) {
                    for (auto p: map[rem]) {
                        res.push_back({p.first, p.second, arr[i], arr[j]});
                    }
                }
            }
            for (int j = 0; j < i; j++) {
                map[arr[i] + arr[j]].insert({arr[i], arr[j]});
            }
        }
        for (vi& v: res) {
            sort(v.begin(), v.end());
        }
        sort(res.begin(), res.end());

        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    vi arr(n);
    fori (i, n) cin >> arr[i];
    
    Solution obj;
    for (vi e: obj.fourSum(arr, k)) {
            for (int x: e) cout << x << ' ';
            cout << endl;
    }
}
