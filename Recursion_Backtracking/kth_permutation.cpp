#include <bits/stdc++.h>
using namespace std;

class Solution {
    int fact[13];

    void solve(int n, int k, vector<int>& digits, string& seq) {

        if (n == 1) {
            seq += to_string(digits.back());
            return;
        }
        int x = k / fact[n - 1];
        if (k % fact[n - 1] == 0) x--;
        k -= fact[n - 1] * x;

        seq += to_string(digits[x]);
        digits.erase(digits.begin() + x);

        solve(n - 1, k, digits, seq);
    }
public:
    string getPermutation(int n, int k) {
        fact[0] = 1;
        for (int i = 1; i < 13; i++) {
            fact[i] = i * fact[i - 1];
        }
        vector<int> digits;
        string seq = "";
        if (n > 13) {
            for (int i = 1; i <= n - 13; i++) seq += to_string(i);
            for (int i = n - 12; i <= n; i++) digits.push_back(i);
            solve(13, k, digits, seq);
        }
        else {
            for (int i = 1; i <= n; i++) digits.push_back(i);
            solve(n, k, digits, seq);
        }
        return seq;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int A, B;
    cin >> A >> B;
    Solution obj;
    cout << obj.getPermutation(A, B);
}