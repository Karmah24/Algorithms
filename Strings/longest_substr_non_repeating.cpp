#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring1(string str) {

        unordered_map<char, int> map;
        int res = 0, unique = 0;
        int i = 0, j = 0;

        while (j < str.size()) {
            if (unique == j - i) {
                res = max(res, j - i);
                if (map[str[j++]]++ == 0) unique++;
            }
            else if (map[str[i++]]-- == 1) unique--;
        }
        return unique == j - i ? max(res, j - i) : res;
    }

    int lengthOfLongestSubstring(string str) {
        unordered_map<char, int> mp;
        int res = 1, i = 0, j = 0;

        for (; j < str.size(); j++) {
            if (mp.count(str[j]) && mp[str[j]] >= i) {
                res = max(res, j - i);
                i = mp[str[j]] + 1;
            }
            mp[str[j]] = j;
        }
        return max(res, j - i);
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string str;
    cin >> str;
    Solution obj;
    cout << obj.lengthOfLongestSubstring(str);
}