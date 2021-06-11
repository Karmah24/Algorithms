#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> getInter(string str) {
        vector<string> intermediates;
        for (int i = 0; i < str.size(); i++) {
            char t = str[i];
            str[i] = '*';
            intermediates.push_back(str);
            str[i] = t;
        }
        return intermediates;
    }
public:
    int ladderLength(string st, string end, vector<string> &dict) {

        dict.push_back(st);
        sort(dict.begin(), dict.end());
        if (!(binary_search(dict.begin(), dict.end(), end))) return 0;
        auto itr = unique(dict.begin(), dict.end());
        dict.resize(itr - dict.begin());

        unordered_map<string, unordered_set<string>> graph;
        for (string str: dict) {
            for (string inter: getInter(str)) {
                graph[inter].insert(str);
            }
        }
        queue<string> qS, qT;
        unordered_set<string> visS, visT;
        unordered_map<string, int> lvlS, lvlT;
        qS.push(st);
        qT.push(end);
        visS.insert(st);
        visT.insert(end);
        lvlS[st] = 1;
        lvlT[end] = 1;
        string u, uT;
        while (!qS.empty() && !qT.empty()) {
            u = qS.front();
            qS.pop();

            for (string inter: getInter(u)) {
                for (string v: graph[inter]) {
                    if (visT.count(v)) return lvlS[u] + lvlT[v];
                    if (visS.count(v)) continue;
                    visS.insert(v);
                    qS.push(v);
                    lvlS[v] = lvlS[u] + 1;
                }
            }
            uT = qT.front();
            qT.pop();
            for (string inter: getInter(uT)) {
                for (string v: graph[inter]) {
                    if (visS.count(v)) return lvlT[uT] + lvlS[v];
                    if (visT.count(v)) continue;
                    visT.insert(v);
                    qT.push(v);
                    lvlT[v] = lvlT[uT] + 1;
                }
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