#include <iostream>
using namespace std;

class Solution {
    pair<int, int> get_Palindrome(string& str, int l, int h) {
        while (l >= 0 && h < str.size()) {
            if (str[l] != str[h]) break;
            l--;
            h++;
        }
        return {l + 1, h};
    }
public:
    string longestPalindrome(string s) {

        pair<int, int> res = {0, 1};
        auto comp = [](pair<int, int> x, pair<int, int> y) {
            return x.second - x.first < y.second - y.first;
        };

        for (int i = 1; i < s.size(); i++) {
            pair<int, int> odd = get_Palindrome(s, i - 1, i + 1);
            pair<int, int> even = get_Palindrome(s, i - 1, i);

            pair<int, int> curr = max(odd, even, comp);
            res = max(res, curr, comp);
        }
        return s.substr(res.first, res.second - res.first);
    }
};

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string str;
    cin >> str;
    Solution obj;
    cout << obj.longestPalindrome(str) << endl;
}