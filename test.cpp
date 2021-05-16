#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
typedef pair<int, int>	pii;
typedef vector<int>		vi;
typedef vector<pii>		vpii;
typedef vector<vi>		vvi;
//=======================

class Solution {
public:
    string minWindow(string str, string pat) {

        unordered_map<char, int> inPat;
        for (char& ch: pat) inPat[ch]++;
        int k = inPat.size();

        unordered_map<char, int> foundMap;
        pair<int, int> res = {0, INT_MAX};
        int i = 0, j = 0, found = 0;

        auto comp = [](pair<int, int> a, pair<int, int> b) {
            return (a.second - a.first) < (b.second - b.first);
        };

        while (j < str.size()) {

            if (found < k) {
                if (++foundMap[str[j]] == inPat[str[j++]]) found++;
            }

            else {
                if (found == k) res = min(res, {i, j}, comp);
                if (foundMap[str[i]]-- == inPat[str[i++]]) found--;
            }
        }
        while (found == k) {
            res = min(res, {i, j}, comp);
            if (foundMap[str[i]]-- == inPat[str[i++]]) found--;
        }
        if (res.second != INT_MAX) return str.substr(res.first, res.second - res.first);
        return "";
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string str, pat;
    cin >> str >> pat;
    Solution obj;
    cout << obj.minWindow(str, pat);
}
