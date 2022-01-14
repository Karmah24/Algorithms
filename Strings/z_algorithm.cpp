#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> getZscore(string &str, int n) {
        
        vector<int> z(n, 0);
        int l = 0, r = 0;
        
        for (int i = 1; i < n; i++) {
            
            if (i > r) {
                l = r = i;
                while (r < n && str[r - l] == str[r]) r++;
                z[i] = r - l;
                r--;
            }
            else {
                int k = i - l;
                if (z[k] < r - i + 1) z[i] = z[k];
                else {
                    while (r < n && str[r - l] == str[r]) r++;
                    z[i] = r - l;
                    r--;
                }
            }
        }
        return z;
    }
public:
    vector<int> search(string pat, string txt) {
        
        string concat = pat + '$' + txt;
        int n = concat.size();
        vector<int> zscore = getZscore(concat, n);
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (zscore[i] == pat.size()) res.push_back(i - pat.size());
        }
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string txt, pat;
    cin >> txt >> pat;
    Solution obj;
    for (int e: obj.search(pat, txt)) cout << e << ' ';
}