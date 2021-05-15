#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
typedef pair<int, int>	pii;
typedef vector<int>		vi;
typedef vector<pii>		vpii;
typedef vector<vi>		vvi;
//=======================

class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        
        unordered_map<int, int> m;
        m[0] = 1;
        int sum = 0, res = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            res += m[sum - k];
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	int n, k;
	cin >> n >> k;
	vi arr(n);
	loop (i, n) cin >> arr[i];
    Solution obj;
    cout << obj.subarraySum(arr, k);
}
