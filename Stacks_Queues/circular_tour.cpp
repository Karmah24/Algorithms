#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
typedef vector<int>		vi;
//=======================

class Solution {
    int prev(int x, int n) {
        return (x - 1 + n) % n;
    }
    int next(int x, int n) {
        return (x + 1) % n;
    }
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& dist) {

        int n = gas.size();
        int l = 0, r = 1;
        int count = 0, bal = 0;

        while (true) {
            bal += gas[prev(r, n)] - dist[prev(r, n)];
            if (bal < 0) {
                bal = 0;
                l = r;
            }
            else if (r == l) return l;
            r = next(r, n);  
            if (++count == 2 * n) return -1;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> gas(n);
    vector<int> dist(n);
    loop (i, n) cin >> gas[i];
    loop (i, n) cin >> dist[i];
    Solution obj;
    cout << obj.canCompleteCircuit(gas, dist);
}
