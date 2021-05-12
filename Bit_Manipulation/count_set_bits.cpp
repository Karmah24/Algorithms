#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count_set_bits(int n) {

        unsigned int count = 0;
        
        // while (n) {
        //     count += n & 1;
        //     n >>= 1;
        // }

        while (n) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    Solution obj;
    cout << obj.count_set_bits(n);
}
