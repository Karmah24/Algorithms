#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMountain1(vector<int>& arr) {
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
    int longestMountain(vector<int>& arr) {

        int n = arr.size();
        vector<int> pre(n, 0), post(n, 0);

        for (int i = 1; i < n; i++) {

            if (arr[i] > arr[i - 1]) pre[i] = pre[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; i--) {

            if (arr[i] > arr[i + 1]) post[i] = post[i + 1] + 1;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {

            if (pre[i] == 0 || post[i] == 0) continue;
            res = max(res, pre[i] + post[i] + 1);
        }
        return res;
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