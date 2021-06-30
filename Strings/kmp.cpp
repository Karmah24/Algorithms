#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> solve(string str, string pat) {
        int n = str.size(), m = pat.size();
        int lps[m];
        for (int& e: lps) e = -1;
        int i = 0, j = 1;
        while (j < m) {
            if (pat[i] == pat[j]) lps[i++] = j++;
            else if (j > 0) j = lps[j - 1] + 1;
            else i++;
        }
        vector<pair<int, int>> all_ocurences;
        i = j = 0; // i leads j
        while (i + m - j <= n) {
            if (str[i] == pat[j]) {
                if (j == m - 1) {
                    all_ocurences.push_back({i - m + 1, i});
                    j = -1;
                    i--;
                }
                i++;
                j++;
            }
            else if (j > 0) j = lps[j - 1] + 1;
            else i++;
        }
        return all_ocurences;
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
    vector<pair<int, int>> all_ocurences = obj.solve(str, pat);
    for (auto e: all_ocurences) cout << e.first << ' ' << e.second << endl;
}
