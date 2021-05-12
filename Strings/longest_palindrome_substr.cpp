#include <iostream>
using namespace std;
typedef pair<int, int> pii;

class Solution {
    pii res;
    pii get_Palindrome(string& str, int l, int h) {
        while (l >= 0 && h < str.size()) {
            if (str[l] != str[h]) break;
            l--;
            h++;
        }
        return {l + 1, h};
    }
public:
    string longestPalindrome(string s) {
        res = {0, 1};

        auto comp = [](pii x, pii y) {
            return x.second - x.first < y.second - y.first;
        };

        for (int i = 1; i < s.size(); i++) {
            pii odd = get_Palindrome(s, i - 1, i + 1);
            pii even = get_Palindrome(s, i - 1, i);

            pii curr = max(odd, even, comp);
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