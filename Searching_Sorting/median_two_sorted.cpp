#include <bits/stdc++.h>
using namespace std;

#define fori(i, n) for (int i = 0; i < n; i++)
typedef vector<int>		vi;
//=======================

class Solution {
    double median(vector<int>& arr) {
        if (arr.size() % 2 != 0) return arr[arr.size() / 2];
        return (arr[arr.size() / 2 - 1] + arr[arr.size() / 2]) / 2;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> arr1 = nums1.size() <= nums2.size() ? nums1 : nums2;
        vector<int> arr2 = nums1.size() > nums2.size() ? nums1 : nums2;

        int n = arr1.size(), m = arr2.size(), lMid, rMid;
        
        if (n == 0) {
            return median(arr2);
        }
        if (n == 1) {
            if (m == 1) return (arr1[0] + arr2[0]) / 2;
            m--;
            if (arr1[0] > arr2[m / 2]) return median(arr2);
            
            if (m % 2 != 0) {
                if (arr1[0] < arr2[m / 2 - 1]) return arr2[m / 2 - 1];
                return arr1[0];
            }
            if (arr1[0] < arr2[m / 2 - 2]) return (arr2[m / 2 - 2] + arr2[m / 2 - 1]) / 2;
            
            return (arr1[0] + arr2[m / 2 - 1]) / 2;
        }
        
        int low = 0, high = n - 1, x = (n + m + 1) / 2;

        while (low <= high) {
            lMid = low + (high - low) / 2;
            rMid = x - lMid - 2;

            if (rMid < 0) return (arr1[1] + arr2[0]) / 2.0;
            if (arr1[lMid] <= arr2[rMid + 1] && arr2[rMid] < arr1[lMid + 1]) break;
            if (arr1[lMid] > arr2[rMid + 1]) high = lMid - 1;
            else low = lMid + 1;
        }

        if (x % 2 != 0) return max(arr1[lMid], arr2[rMid]);
        return (max(arr1[lMid], arr2[rMid]) + min(arr1[lMid + 1], arr2[rMid + 1])) / 2;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vi nums1(n);
    vi nums2(m);
    fori (i, n) cin >> nums1[i];
    fori (i, m) cin >> nums2[i];
    Solution obj;
    cout << obj.findMedianSortedArrays(nums1, nums2);
}
