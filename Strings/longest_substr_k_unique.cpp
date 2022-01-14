#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestKSubstr(string str, int k) {
        int n = str.size();
        unordered_map<char, int> m;
        int i = 0, j = 0;
        int unique = 0, res = 0;

        while (j < n) {           
            if (unique <= k) {
                if (unique == k) res = max(res, j - i);
                if (m[str[j++]]++ == 0) unique++;
            }
            else if (m[str[i++]]-- == 1) unique--;
        }
        return unique == k ? max(res, j - i) : res;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string str;
    cin >> str;
    int k;
    cin >> k;
    Solution obj;
    cout << obj.longestKSubstr(str, k);
}
