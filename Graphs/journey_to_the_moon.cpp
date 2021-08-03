#include <bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    vector<int> par, rank;
    unordered_set<int> roots;
    UnionFind(int n) {
        rank = vector<int>(n, 1);
        par = vector<int>(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            roots.insert(i);
        }
    }
    int find(int x) {
        if (par[x] != x) par[x] = find(par[x]);
        return par[x];
    }
    void _union(int x, int y) {
        int set_x = find(x), set_y = find(y);
        if (set_x == set_y) return;
        if (rank[set_x] <= rank[set_y]) {
            par[set_x] = set_y;
            roots.erase(set_x);
            rank[set_y] += rank[set_x];
        }
        else {
            par[set_y] = set_x;
            roots.erase(set_y);
            rank[set_x] += rank[set_y];
        }
    }
};

int journeyToMoon(int n, vector<vector<int>> &astronaut) {

    UnionFind uf(n);
    for (auto p: astronaut) uf._union(p[0], p[1]);

    int rem = n, res = 0;
    for (int root: uf.roots) {
        rem -= uf.rank[root];
        res += uf.rank[root] * rem;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> pairs(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> pairs[i][0] >> pairs[i][1];
    }
    cout << journeyToMoon(n, pairs);
}