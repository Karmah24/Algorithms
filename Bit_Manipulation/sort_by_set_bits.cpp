#include <bits/stdc++.h>
using namespace std;

class Solution{
    
    int get_set_bits(int a) {
        int x = 0;
        while (a) {  
            x++;
            a = a & (a - 1);
        }
        return x;
    }
        
    public:
    void sortBySetBitCount(int arr[], int n) {
        
        vector<vector<int>> table(32);
        for (int i = 0; i < n; i++) {
            table[get_set_bits(arr[i])].push_back(arr[i]);
        }
        int i = 0;
        for (int j = 31; j >= 0; j--) {
            for (int k = 0; k < table[j].size(); k++) {
                arr[i++] = table[j][k];
            }
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
    for(int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    obj.sortBySetBitCount(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << ' ';
}
