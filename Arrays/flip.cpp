#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> flip(string arr) {
    
        int i = 0, j, n = arr.size();
        
        while (i < n && arr[i] == '1') i++;
        
        j = i;
        int bal = 0, flip = 0;
        vector<int> res = {n, n};
        
        while (j < n) {
            if (arr[j] == '1') bal--;
            else bal++;
            
            if (bal < 0) {
                bal = 0;
                i = j + 1;
                j = i;
                continue;
            }
            if (bal > flip) {
                flip = bal;
                res[0] = i;
                res[1] = j;
            }
            j++;
        }
        if (res[0] == n) return {};
        res[0]++, res[1]++;
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
    for (int e: obj.flip(str)) cout << e << " ";
}