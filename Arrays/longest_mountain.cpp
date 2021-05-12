#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if (arr.size() < 3)
            return 0;
        int n = arr.size(), res = 0;
        int asc = 0, des = 0, i = 1;
        
        while (i < n) {
            if (arr[i] > arr[i - 1]) {
                if (des != 0) {
                    res = max(res, des);
                    des = 0;
                    asc = 0;
                }
                asc++;
            }
            else if (arr[i] < arr[i - 1] && asc != 0) {
                if (des == 0)
                    des = asc;
                des++;
            }
            else {
                res = max(res, des);
                des = 0;
                asc = 0;
            }
            i++;
        }
        
        if (des != 0 && asc != 0)
            res = max(res, des);
        if (res != 0)
            return res + 1;
        return 0;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    Solution obj;
    cout << obj.longestMountain(a);
}