#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string str) {
        
        int i = str.size() - 1, n = str.size();
        
        while (i > 0 && str[i] <= str[i - 1]) {
            i--;
        }
        if (i == 0) return "-1";
        int j = i;
        while (j < n && str[j] > str[i - 1]) j++;
        swap(str[i - 1], str[j - 1]);
        reverse(str.begin() + i, str.end());

        return str;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string str;
    cin >> str;
    Solution obj;
    cout << obj.solve(str);
}