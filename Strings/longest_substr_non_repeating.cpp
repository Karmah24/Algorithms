#include <bits/stdc++.h>
using namespace std;

#define fori(i, n) for (int i = 0; i < n; i++)
//=======================

class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        unordered_map<char, int> map;
        int res = 0, start = 0;

        fori (i, str.size()) {
            if (map.find(str[i]) != map.end()) start = max(start, map[str[i]] + 1);
            res = max(res, i + 1 - start);
            map[str[i]] = i;
        }
        return res;        
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int T = 1;
    cin >> T;
    cin.ignore();
    while (T--) {
        string in;
        cin >> in;
        Solution obj;
        cout << obj.lengthOfLongestSubstring(in) << endl;
    }
}
