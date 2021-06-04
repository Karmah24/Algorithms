#include <bits/stdc++.h>
using namespace std;

struct Job {
    int dead, profit;
};

class DSU {
    int *par;
public:
    DSU(int n) {
        par = new int[n + 1];
        for (int i = 0; i < n + 1; i++) par[i] = i;
    }
    int find(int s) {
        if (s == par[s]) return s;
        return par[s] = find(par[s]);
    }
    void merge(int u, int v) {
        par[v] = find(u);
    }
};

class Solution  {
public:
    vector<int> JobScheduling(Job arr[], int n)  {

        auto comp = [](Job a, Job b) {
            return a.profit > b.profit;
        };
        sort(arr, arr + n, comp);

        int max_dead = INT_MIN;
        for (int i = 0; i < n; i++) {
            max_dead = max(max_dead, arr[i].dead);
        }
        DSU dsu(max_dead);

        vector<int> res(2);
        for (int i = 0; i < n; i++) {
            int availDead = dsu.find(arr[i].dead);
            if (availDead == 0) continue;
            dsu.merge(availDead - 1, availDead);
            res[0]++;
            res[1] += arr[i].profit;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    Job arr[n];
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        arr[i].dead = x;
        arr[i].profit = y;
    }
    Solution obj;
    for (int e: obj.JobScheduling(arr, n)) cout << e << " ";
}