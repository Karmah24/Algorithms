#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
typedef vector<int>		vi;
typedef vector<vi>		vvi;
//=======================

class Solution  {
public:
    int findCelebrity(vector<vector<int> >& M, int n)  {
        
        stack<int> s;
        loop (i, n) s.push(i);

        while (s.size() > 1) {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();

            if (M[a][b] == 0) s.push(a);
            else s.push(b);
        }
        int x = s.top();
        loop (i, n) {
            if (M[x][i] == 1) return -1;
            if (i != x && M[i][x] == 0) return -1;
        }
        return x;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vvi M(n, vi(n));
    loop (i, n) loop (j, n) cin >> M[i][j];
    Solution obj;
    cout << obj.findCelebrity(M, n);
}
