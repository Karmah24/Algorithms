#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
typedef vector<int>		vi;
//=======================

class Solution {
public:
    int search(vector<int>& arr, int target) {

        int lo = 0, hi = arr.size() - 1;

        while (lo <= hi) {

            int mid = (lo + hi) / 2;

            if (arr[mid] == target) return mid;
            if (arr[lo] <= arr[mid]) {

                if (arr[lo] <= target && target < arr[mid]) hi = mid - 1;
                else lo = mid + 1;
            }
            else {
                if (arr[mid] < target && target <= arr[hi]) lo = mid + 1;
                else hi = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    vi nums(n);
    loop (i, n) cin >> nums[i];
    Solution obj;
    cout << obj.search(nums, k) << endl;
}
