#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> search(string pat, string str) {

        int n = str.size(), m = pat.size();
        vector<int> lps(m, -1);

        int i = 0, j = 1;
        while (j < m) {
            if (pat[i] == pat[j]) lps[j++] = i++;
            else if (i > 0) i = lps[i - 1] + 1;
            else j++;
        }
        vector<int> res;
        i = j = 0;
        while (i + m - j <= n) {

            if (str[i] == pat[j]) {
                i++, j++;
                if (j == m) {
                    res.push_back(i - m + 1);
                    j = lps[j - 1] + 1;
                }
            }
            else if (j > 0) j = lps[j - 1] + 1;
            else i++;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string str, pat;
    getline(cin, str);
    cin >> pat;
    Solution obj;
    for (int e: obj.search(pat, str)) cout << e << " ";
}
