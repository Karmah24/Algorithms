#include<bits/stdc++.h>

using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
#define pb push_back
void ipgraph(int n);
void dfs(string s);
const int N = 3e5, M = N;
//=======================

vector<string> graph[26];
vector<string> tp[26];
vector<string> words;

bool check_deg() {
    for (string v : words) {
        if (graph[v[v.size() - 1] - 'a'])
    }
}
bool solve() {
    int n;
    cin >> n;
    ipgraph(n);
    if (!check_deg())
        return 0;
    
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cout << solve() << endl;
        for (auto& v : graph) 
            v.clear();
        for (auto& v : tp)
            v.clear();
    }
    return 0;
}

void ipgraph(int n){
    string s;
    while (n--) {
        cin >> s;
        graph[s[0] - 'a'].pb(s);
    }
    words.pb(s);
}

void dfs(string s) {
    st.insert(s);
    for (string v : graph[s[s.size()-1] - 'a']) {
        if (unvis.find(v) != unvis.end()) {
            unvis.erase(unvis.find(v));
            dfs(v);
        }
    }
    st.erase(st.find(s));
}