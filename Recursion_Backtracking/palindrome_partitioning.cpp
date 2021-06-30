#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<string>> partitions;
    vector<vector<bool>> isPd;

    void getPartions(string& str, int i, vector<string>& partition) {

        if (i == str.size()) {
            partitions.push_back(partition);
            return;
        }
        for (int j = i; j < str.size(); j++) {
            if (!isPd[i][j]) continue;

            partition.push_back(str.substr(i,  j - i + 1));
            getPartions(str, j + 1, partition);
            partition.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string str) {
    
        int n = str.size();
        partitions.clear();
        isPd = vector<vector<bool>>(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            isPd[i][i] = true;

            for (int j = i + 1; j < n; j++) {
                if (str[i] != str[j]) continue;

                if (j - i == 1 || isPd[i + 1][j - 1]) isPd[i][j] = true;
                else isPd[i][j] = false;
            }
        }
        vector<string> partition;
        getPartions(str, 0, partition);
        return partitions;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string str;
    cin >> str;
    Solution obj;
    for (auto v: obj.partition(str)) {
        for (string s: v) cout << s << " ";
        cout << endl;
    }
}