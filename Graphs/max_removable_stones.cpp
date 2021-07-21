#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    unordered_map<int, int> par, rank;
public:
    int count;
    UnionFind(vector<vector<int>> &stones) {

        for (auto stone: stones) {
            int row = -(stone[0] + 1);
            int col = stone[1] + 1;
            par[row] = row;
            par[col] = col;
        }
        count = par.size();
    }
    int find(int x) {
        if (par[x] != x) par[x] = find(par[x]);
        return par[x];
    }
    void _union(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);

        if (x_root == y_root) return;
        count--;

        if (rank[x_root] <= rank[y_root]) {
            par[x_root] = y_root;
            if (rank[x_root] == rank[y_root]) rank[y_root]++;
        }
        else {
            par[y_root] = x_root;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        UnionFind uf(stones);

        for (auto stone: stones) {
            int row = -(stone[0] + 1);
            int col = stone[1] + 1;
            uf._union(row, col);
        }
        return stones.size() - uf.count;
    }
};