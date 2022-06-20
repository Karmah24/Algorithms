#include <bits/stdc++.h>
using namespace std;
#define ll long long
//================================================================

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {

        vector<unordered_set<string>> suff(26);
        
        for (auto &idea: ideas) {
            suff[idea[0] - 'a'].insert(idea.substr(1));
        }
        ll res = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = i + 1; j < 26; j++) {
                
                int intersect = 0;
                for (auto &s: suff[i]) {
                    intersect += suff[j].count(s);
                }
                res += 2 * (suff[i].size() - intersect) * (suff[j].size() - intersect);
            }
        }
        return res;
    }
};

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    Solution obj;
    int n;
    cin >> n;
    vector<string> ideas(n);
    for (int i = 0; i < n; i++) {
        cin >> ideas[i];
    }
    cout << obj.distinctNames(ideas);

    return 0;
}