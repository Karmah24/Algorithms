#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCut(string s) {

        int n = s.size();
        bool P[n][n];

        for (int i = n - 1; i >= 0; i--) {
            P[i][i] = true;

            for (int j = i + 1; j < n; j++) {
                if (s[i] != s[j]) continue;

                if (j - i == 1 || P[i + 1][j - 1]) P[i][j] = true;
                else P[i][j] = false;
            }
        }
        int cuts[n];
        for (int& e: cuts) e = 0;

        for (int i = 1; i < n; i++) {
            
            if (P[0][i]) continue;

            cuts[i] = cuts[i - 1] + 1;
            if (cuts[i] == 1) continue;
            
            for (int j = 1; j < i; j++) {
                if (P[j][i]) {
                    cuts[i] = min(cuts[i], cuts[j - 1] + 1);
                    // break;
                }
            }
        }
        return cuts[n - 1];
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
    Solution obj;
    string s;
    cin >> s;
    cout << obj.minCut(s);
}