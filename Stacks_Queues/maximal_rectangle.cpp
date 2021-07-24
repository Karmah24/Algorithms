#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int n, vector<int> &arr) {
        
        stack<int> st;
        st.push(-1);
        int i = 0, res = 0;
        
        while (i < n) {
            
            if (st.top() == -1 || arr[i] >= arr[st.top()]) st.push(i++);
            else {
                int curr = st.top();
                st.pop();
                res = max(res, arr[curr] * (i - st.top() - 1));
            }
        }
        while (st.top() != -1) {
            int curr = st.top();
            st.pop();
            res = max(res, arr[curr] * (n - st.top() - 1));
        }
        return res;
    }
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        
        if (mat.size() == 0) return 0;
        int R = mat.size(), C = mat[0].size();
        vector<int> sub(C, 0);
        int res = 0;
        for (int i = 0; i < R; i++) {
                
            for (int j = 0; j < C; j++) {
                if (mat[i][j] == '0') sub[j] = 0;
                else sub[j]++;
            }
            res = max(res, solve(C, sub));
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> M(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> M[i][j];
    }
    Solution obj;
    cout << obj.maximalRectangle(M);
}