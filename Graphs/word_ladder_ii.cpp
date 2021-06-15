#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, vector<string>> graph;

    vector<string> getInter(string str) {
        vector<string> inters;
        for (int i = 0; i < str.size(); i++) {
            char t = str[i];
            str[i] = '*';
            inters.push_back(str);
            str[i] = t;
        }
        return inters;
    }

    void dfs(string u, string end, int x, vector<string> &path, unordered_set<string> &vis, vector<vector<string>> &res) {

        if (x == 0) {
            if (u == end) res.push_back(path);
            return;
        }
        vis.insert(u);
        for (string inter: getInter(u)) {
            for (string v: graph[inter]) {
                if (vis.count(v)) continue;
                path.push_back(v);
                dfs(v, end, x - 1, path, vis, res);
                path.pop_back();
            }
        }
        vis.erase(u);
    }

    int shortestPath(string st, string end) {
        queue<string> qS, qT;
        unordered_map<string, int> lvlS, lvlT;
        qS.push(st);
        qT.push(end);
        lvlS[st] = 1;
        lvlT[end] = 1;
        string u, uT;
        int pathLen = 0;
        while (!qS.empty() && !qT.empty()) {
            u = qS.front();
            qS.pop();

            for (string inter: getInter(u)) {
                for (string v: graph[inter]) {
                    if (lvlT.count(v)) return lvlS[u] + lvlT[v];
                    if (lvlS.count(v)) continue;
                    qS.push(v);
                    lvlS[v] = lvlS[u] + 1;
                }
            }
            uT = qT.front();
            qT.pop();
            for (string inter: getInter(uT)) {
                for (string v: graph[inter]) {
                    if (lvlS.count(v)) return lvlT[uT] + lvlS[v];
                    if (lvlT.count(v)) continue;
                    qT.push(v);
                    lvlT[v] = lvlT[uT] + 1;
                }
            }
        }
        return -1;
    }
public:
    vector<vector<string>> findLadders(string st, string end, vector<string> &dict) {

        sort(dict.begin(), dict.end());
        auto itr = unique(dict.begin(), dict.end());
        dict.resize(itr - dict.begin());

        graph = unordered_map<string, vector<string>>();
        for (string str: dict) {
            for (string inter: getInter(str)) graph[inter].push_back(str);
        }

        int pathLen = shortestPath(st, end);
        if (pathLen == -1) return {};
        unordered_set<string> vis = {st};
        vector<vector<string>> res;
        vector<string> path = {st};
        dfs(st, end, pathLen - 1, path, vis, res);
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<string> dict(n);
    for (int i = 0; i < n; i++) cin >> dict[i];
    Solution obj;
    for (auto v: obj.findLadders(dict[0], dict[1], dict)) {
        for (string s: v) cout << s << " ";
        cout << endl;
    }
}