#include <bits/stdc++.h>
using namespace std;

#define fori(i, n) for (int i = 0; i < n; i++)
#define pb push_back
typedef vector<int> vi;

const int N = 1e5;
//=========================

int n; 
vi graph[N];
int depth[N] = { };

void ipgraph();

void dfs(int, int);

void solve() {
    cin >> n;
    int evens = 0, odds = 0;
    ipgraph();
    dfs(0, -1);
    fori(i, n) {
        if (depth[i] % 2 == 0) evens++;
        else odds++;
    }
    int pairs = ((odds * (odds - 1)) / 2) + ((evens * (evens - 1)) / 2);
    cout << "#res " << pairs << endl;  
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
        for (auto& v : graph) 
            v.clear();
    }
}

void dfs(int s, int  parent) {
    for (int y : graph[s]) {
        if (y == parent) continue;
        depth[y] = depth[s] + 1;
        dfs(y, s);
    }
}

void ipgraph() {
    int u, v;
    fori (i, n - 1) {
        cin >> u >> v;
        u--, v--;
        graph[u].pb(v);
        graph[v].pb(u);
    }
}
