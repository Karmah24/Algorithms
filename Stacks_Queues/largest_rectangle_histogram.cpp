#include <bits/stdc++.h>
using namespace std;

#define ll long long
//=======================

class Solution {
public:
    ll getMaxArea(vector<ll> &arr, int n) {

        stack<int> st;
        st.push(-1);
        ll res = 0, curr, area;
        int i = 0;
        while (i < n) {

            if (st.top() == -1 || arr[st.top()] <= arr[i]) st.push(i++);
            else {
                curr = st.top();
                st.pop();
                res = max(res, arr[curr] * (i - st.top() - 1));
            }
        }
        while (st.top() != -1) {
            curr = st.top();
            st.pop();
            res = max(res, arr[curr] * (n - st.top() - 1));
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
    vector<ll> arr(n); 
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    cout << obj.getMaxArea(arr, n);
}
