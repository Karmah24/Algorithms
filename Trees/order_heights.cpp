#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> order(vector<int> &A, vector<int> &B) {

        vector<int> ans(A.size(), -1);
        vector<pair<int, int>> v;
        for (int i = 0; i < A.size(); i++) v.push_back({A[i], B[i]});
        sort(v.begin(), v.end());

        vector<int > aux;
        for(int i = 0; i < A.size(); i++){
            aux.push_back(i);
        }
        for(int i = 0; i < v.size(); i++){
            ans[aux[v[i].second]] = v[i].first;
            auto it = aux.begin();
            aux.erase(it+v[i].second);
        }
        return ans;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];

    Solution obj;
    for (int e: obj.order(A, B)) cout << e << " ";
}