#include <bits/stdc++.h>
using namespace std;

class Solution {
    // unordered_map<string, vector<int>> mp;

    // vector<int> mapCounts(string s) {
    //     vector<int> counts(26);
    //     for (char ch: s) {
    //         counts[ch - 'a']++;
    //     }
    //     return counts;
    // }
    // bool diff(string s1, string s2) {
    //     int x = 0;
    //     for (int i = 0; i < 26; i++) {
    //         x += abs(mp[s1][i] - mp[s2][i]);
    //         if (x > 2) return 0;
    //     }
    //     return 1;
    // }
    bool adj(string s1, string s2) {
        int x = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) x++;
            if (x > 1) return 0;
        }
        return 1;
    }
public:
    int ladderLength(string s1, string s2, vector<string> &v) {
        if (s1 == s2) return 0;
        unordered_set<string> st;
        vector<string> dict;
        dict.push_back(s1);
        st.insert(s1);
        for (string s: v) {
            if (st.find(s) != st.end() || s == s2) continue; 
            dict.push_back(s);
            st.insert(s);
        }
        dict.push_back(s2);
        // mp.clear();
        // for (string &s: dict) {
        //     mp[s] = mapCounts(s);
        // }
        vector<int> graph[dict.size()];

        for (int i = 0; i < dict.size() - 1; i++) {
            for (int j = i + 1; j < dict.size(); j++) {
                if (adj(dict[i], dict[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        queue<int> q;
        vector<bool> vis(dict.size(), false);
        q.push(0);
        vis[0] =  true;
        int res = 1, x = 1;
        while (!q.empty()) {
            
            int u = q.front();
            q.pop();
            for (int v: graph[u]) {
                if (v == dict.size() - 1) return res + 1;
                if (vis[v]) continue;
                vis[v] = true;
                q.push(v);
            }
            if (--x == 0) {
                res++;
                x = q.size();
            }
        }
        return 0;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    string s1, s2;
    cin >> s1 >> s2 >> n;
    vector<string> dict(n);
    for (int i = 0; i < n; i++) cin >> dict[i];
    Solution obj;
    cout << obj.ladderLength(s1, s2, dict);
}