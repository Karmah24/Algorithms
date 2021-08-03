#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
        
        vector<int> diff(n, 0);
        
        for (auto &booking: bookings) {
            diff[booking[0] - 1] += booking[2];
            if (booking[1] < n) diff[booking[1]] -= booking[2];
        }
        vector<int> res(n, 0);
        res[0] = diff[0];
        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
};