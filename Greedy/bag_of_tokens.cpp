#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin(), tokens.end());
        int res = 0, curr = 0;
        int i = 0, j = tokens.size() - 1;

        while (i <= j) {

            if (power >= tokens[i]) {
                power -= tokens[i++];
                curr++;
                res = max(res, curr);
            }
            else if (curr > 0) {
                curr--;
                power += tokens[j--];
            }
            else break;
        }
        return res;
    }
};