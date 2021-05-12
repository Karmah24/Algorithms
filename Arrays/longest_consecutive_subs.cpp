#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    // int findLongestConseqSubseq(int arr[], int n) {
        
    //     sort(arr, arr + n);
        
    //     int i = 1, res = 0, count = 0;
    //     while (i < n) {
            
    //         if (arr[i] == arr[i - 1]) {
    //             i++;
    //             continue;
    //         }
            
    //         if (arr[i] == arr[i - 1] + 1) count++;
    //         else {
    //             res = max(res, count);
    //             count = 0;
    //         }
    //         i++;
    //     }
    //     res = max(res, count);
    //     return res + 1;
    // }
    int findLongestConseqSubseq(int arr[], int n) {
        
        unordered_set<int> s;
        for (int i = 0; i < n; i++) s.insert(arr[i]);

        int res = 0;
        for (int i = 0; i < n; i++) {

            if (s.find(arr[i]) == s.end()) continue;

            int l = arr[i], r = arr[i];
            while (s.find(l - 1) != s.end()) {
                s.erase(s.find(l - 1));
                l--;
            }
            while (s.find(r + 1) != s.end()) {
                s.erase(s.find(r + 1));
                r++;
            }
            res = max(res, r - l);
        }
        return res + 1;
    }
};

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	Solution obj;
	cout << obj.findLongestConseqSubseq(arr, n);
}