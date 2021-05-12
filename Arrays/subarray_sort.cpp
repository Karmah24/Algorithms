#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
typedef pair<int, int>	pii;
typedef vector<int>		vi;
//=======================

class Solution {
public:
    bool isSorted(int i, vector<int>& arr) {
        if (i == 0) return arr[i] < arr[i + 1];
        if (i == arr.size() - 1) return arr[i] > arr[i - 1];
        return arr[i] > arr[i - 1] && arr[i] < arr[i + 1];
    }
    pii findUnsortedSubarray(vector<int>& arr) {
        int unsorted_min = INT_MAX, unsorted_max = INT_MIN;
        loop (i, arr.size()) {
            if (!isSorted(i, arr)) {
                unsorted_min = min(unsorted_min, arr[i]);
                unsorted_max = max(unsorted_max, arr[i]);
            }
        }
        if (unsorted_min == INT_MAX) return {-1, -1};
        int i = 0;
        while (arr[i] < unsorted_min) i++;
        int j = arr.size() - 1;
        while (arr[j] > unsorted_max) j--;
        return {i, j};
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int T = 1;
    string s; getline(cin, s);
    stringstream num(s); num >> T;
    while (T--) {
        vi nums; string in;
        getline(cin, in); istringstream iss(in);
        while (getline(iss, s, ',')) {
            stringstream num(s);
            int k; num >> k;
            nums.push_back(k);
        } 
        Solution obj;
        pii res = obj.findUnsortedSubarray(nums);
        cout << res.first << ' ' << res.second << endl;
    }
}
