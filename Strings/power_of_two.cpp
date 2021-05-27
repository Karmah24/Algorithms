#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(string str) {

        int i = 0, j, rem = 0;
        while (i < str.size() - 1) {
            j = i;
            while (j < str.size()) {
                int x = str[j] - '0' + rem * 10;
                str[j] = (x / 2) + '0';
                rem = x % 2;
                j++;
            }
            if (rem != 0) return false;
            while (i < str.size() - 1 && str[i] == '0') i++;
        }
        int last = str[str.size() - 1] - '0';
        if (last == 0 || last == 2 || last == 8) return true;
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string n;
    cin >> n;
    Solution obj;
    cout << obj.solve(n);
}