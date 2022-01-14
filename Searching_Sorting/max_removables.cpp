#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isSubsequence(string &s1, string &s2) {

        int j = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s2[j]) j++;
        }
        return j == s2.size() ? true : false;
    }
public:
    int maxRemovals(string s, string p, vector<int> &rem) {

        vector<int> map(s.size(), INT_MAX);
        for (int i = 0; i < rem.size(); i++) map[rem[i]] = i;

        int l = 0, r = rem.size();
        while (l <= r) {
            int mid = (l + r) / 2, j = 0;
            
            for (int i = 0; i < s.size(); i++) {
                if (map[i] >= mid && s[i] == p[j]) j++;
            }
            if (j == p.size()) l = mid + 1;
            else r = mid - 1;
        }
        if (l > r) return r;
        return l;
    }
    int maxRemovals1(string s, string p, vector<int> &rem) {

        string str = s;
        int l = 0, r = rem.size(), n = s.size(), res = 0;
        while (l <= r) {

            int mid = (l + r) / 2;
            for (int i = 0; i < mid; i++) str[rem[i]] = '*';
            if (isSubsequence(str, p)) {
                res = mid;
                l = mid + 1;
                continue;
            }
            str = s;
            r = mid - 1;
        }
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string s1, s2;
    cin >> s1 >> s2;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    cout << obj.maxRemovals(s1, s2, arr);
}