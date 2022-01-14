#include<bits/stdc++.h>

using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
typedef pair<int, int>	pii; 
const int N = 3e5, M = N;

//===================================

bool vis[N] = { };
int arr[N];
pii i_map[N];

void solve() {
    int n, s_min = 0;
    cin >> n;
    loop (i, n) {
        cin >> arr[i];
        i_map[i].first = arr[i];
        i_map[i].second = i;
    }
    sort(i_map, i_map + n);
    loop (i ,n) {
        if (vis[i] || i_map[i].second == i) continue;
        
        int j = i, c_size = 0;
        while (!vis[j]) {
            vis[j] = true;
            c_size++;
            j = i_map[j].second;
        }
        s_min += c_size - 1;
    }
    cout << s_min << endl;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
        for (auto &v : vis)
            v = false;
    }
    return 0;
}