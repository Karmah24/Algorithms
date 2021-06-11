#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int> &arr) {
    
        int n = arr.size();
        vector<int> rg(n);
        rg[n - 1] = -1; 
        for (int i = n - 2; i >= 0; i--) {
            rg[i] = max(rg[i + 1], arr[i + 1]);
        }
        int res = 0;
        set<int> st;
        st.insert(arr[0]);
        for (int i = 1; i < n - 1; i++) {
            
            st.insert(arr[i]);
            if (arr[i] <= *st.begin() || arr[i] >= rg[i]) continue;
            auto x = st.find(arr[i]);
            res = max(res, arr[i] + *(--x) + rg[i]);
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    cout << obj.solve(arr);
}