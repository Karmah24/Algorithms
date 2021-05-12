#include<bits/stdc++.h>

using namespace std;

#define fori(i, n) for (int i = 0; i < n; i++)
#define pb push_back
typedef vector<int>	    vi;
void ipgraph(int n, int m);
void dfs(int s);
const int mod = int(1e9 + 7);
const int N = 3e5, M = N;
//=======================

struct vert {
    int pos, rank;
    vert* par;
    vert(int pos) {
        this->pos = pos;
        rank = 0;
        par =  NULL;
    }
};
vector<pair<vert, vert>> edges;

vert find(vert v) {
    if (v.par == NULL)
        return v;
    *(v.par) = find(*(v.par));
    return *(v.par);
}

void union(vert x, vert y) {

}

bool solve() {
    int n, m;
    cin >> n >> m;
    ipgraph(n, m);

    for (auto e : edges) {
        if (find(e.first()) == find(e.second()))
            return 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cout << solve() << endl;
        edges.clear();
    }
    return 0;
}

void ipgraph(int n, int m){
    int u, v;
    cin >> u >> v;
    edges.pb({vert(u), vert(v)});
}