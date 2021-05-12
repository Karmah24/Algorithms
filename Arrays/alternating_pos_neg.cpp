#include <bits/stdc++.h>
using namespace std;

class Solution {
    void rightRot(int arr[], int n, int lo, int hi) {
        
        int st = arr[hi];
        for (int i = hi; i > lo; i--) {
            arr[i] = arr[i - 1];
        }
        arr[lo] = st;
    }
public:
	void rearrange(int arr[], int n) {
	    
	    int i = 0;
	    while (i < n) {
	        
	        if ((arr[i] >= 0 && i % 2 == 0) || (arr[i] < 0 && i % 2 == 1)) {
	            i++;
	            continue;
	        }
	        bool pos = arr[i] >= 0;
	        int j = i + 1;
	        while (arr[j] >=0 == pos && j < n) {
	            j++;
	            continue;
	        }
	        if (j == n) return;
	        rightRot(arr, n, i, j);
	    }
	}
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    obj.rearrange(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
