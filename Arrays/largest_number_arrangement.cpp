#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(vector<int>& arr) {

        vector<string> v;
        for (int& e: arr) v.push_back(to_string(e));

        auto comp = [](string a, string b) {
            return a + b > b + a;
        };
        sort(v.begin(), v.end(), comp);

        string res = "";
        for (string& str: v) if (str != "0") res += str;
        
        return res == "" ? "0" : res;
    }
    // int firstDig(int n) {

    //     while (n / 10) {
    //         n /= 10;
    //     }
    //     return n;
    // }
    // string solve(vector<int>& arr) {
        
    //     int n = arr.size();
    //     vector<vector<string>> buckets(9);

    //     for (int i = 0; i < n; i++) {
    //         if (arr[i] == 0) continue;
    //         buckets[firstDig(arr[i]) - 1].push_back(to_string(arr[i]));
    //     }

    //     auto comp = [](string a, string b) {
    //         if (a.size() == b.size()) return a > b;

    //     };
    //     for (auto &v: buckets) {
            
    //         auto itr = v.begin();
    //         // while (itr != v.end() && (*itr).size() == 1) itr++;
        
    //         sort(itr, v.end(), comp);
    //     }
    //     string res = "";
    //     for (int i = 8; i >= 0; i--) {
    //         for (auto &str: buckets[i]) {
    //             res += str;
    //         }
    //     }
    //     if (res == "") return "0";
    //     return res;
    // }
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