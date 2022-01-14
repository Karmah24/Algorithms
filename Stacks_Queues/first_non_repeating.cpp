#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for (int i = 0; i < n; i++)
//=======================

void solve() {
    int n;
    cin >> n;
    vector<char> in(n);
    loop (i, n)
        cin >> in[i];
        
    int freq[26];
    for (int &i : freq)
        i = 0;
    queue<char> q;
    loop (i, n) {
        freq[in[i] - 'a']++;
        q.push(in[i]);

        while (!q.empty()) {
            if (freq[q.front() - 'a'] == 1) {
                cout << q.front() << " ";
                break;
            }
            else 
                q.pop();
        }
        if (q.empty())
            cout << -1 << " ";
    }
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}