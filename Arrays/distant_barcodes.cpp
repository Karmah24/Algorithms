#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrange(vector<int> &barcodes) {

        unordered_map<int, int> mp;
        for (int e: barcodes) mp[e]++;

        priority_queue<pair<int, int>> pq;
        for (auto p: mp) pq.push({p.second, p.first});

        int idx = 0;
        while (!pq.empty()) {

            auto [freq, key] = pq.top();
            pq.pop();

            while (freq--) {
                if (idx >= barcodes.size()) idx = 1;
                barcodes[idx] = key;
                idx += 2;
            }
        }
        return barcodes;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    for (int e: obj.rearrange(arr)) cout << e << " ";
}