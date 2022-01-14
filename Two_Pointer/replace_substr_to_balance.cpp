#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int balanceString(string str) {

        int n = str.size();
        int k =  n / 4;
        unordered_map<char, int> mp;
        for (char ch: str) mp[ch]++;

        if (mp['Q'] == mp['W'] && mp['W'] == mp['E'] && mp['E'] == mp['R']) return 0;

        int i = 0, j = 0, res = n;
        while (j < n) {

            mp[str[j]]--;
            while (mp['Q'] <= k && mp['W'] <= k && mp['E'] <= k && mp['R'] <= k) {

                res = min(res, j - i + 1);
                mp[str[i]]++;
                i++;
            }
            j++;
        }
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string str;
    cin >> str;
    Solution obj;
    cout << obj.balanceString(str);
}