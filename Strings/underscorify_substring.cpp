#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
typedef pair<int, int>	pii;
typedef vector<int>     vi;
typedef vector<pii>		vpii;
//=======================

class Solution {
    vpii kmp(string str, string pat) {
        int n = str.size(), m = pat.size();
        int lps[m];
        for (int& e: lps) e = -1;
        int j = 0, i = 1;
        while (i < m) {
            if (pat[i] == pat[j]) lps[i++] = j++;
            else if (j > 0) j = lps[j - 1] + 1;
            else i++;
        }
        vpii all_ocurences;
        i = j = 0;
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
    vi collapse(vpii& all_occurences) {
        vi collapsed;
        int f = 0, s;
        loop (i, all_occurences.size()) {
            s = all_occurences[i].second;
            if (i == all_occurences.size() - 1 || 
                all_occurences[i].second >= all_occurences[i + 1].first - 1) continue;
            else {
                collapsed.push_back(f);
                collapsed.push_back(s + 1);
                f = all_occurences[i + 1].first;
            }
        }
        collapsed.push_back(f);
        collapsed.push_back(s + 1);
        return collapsed;
    }
public:
    string solve(string str, string pat) {
        vpii all_occurences = kmp(str, pat);
        if (all_occurences.size() == 0) return str;
        vi collapsed = collapse(all_occurences);
        int j = 0, i;
        string res;
        for (i = 0; i < str.size() && j < collapsed.size(); i++) {
            if (i == collapsed[j]) { 
                res.push_back('_');
                j++;
            }
            res.push_back(str[i]);
        }
        while (i < str.size()) res.push_back(str[i++]);
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
    cout << obj.solve(str, pat) << endl;
}
