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
    int evaluatePostfix(string str) {
        
        list<int> ls;
        ls.push_back(1);
        ls.push_back(2);
        ls.push_back(3);
        ls.push_front(4);
        cout << ls.front() << endl;
        ls.pop_front();
        cout << ls.front() << endl;
        return 0;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string str;
    cin >> str;
    Solution obj;
    cout << obj.evaluatePostfix(str);
}
