#include <bits/stdc++.h>
using namespace std;

string solve() {
    
    int n;
    cin >> n;

    if (n % 2 != 0) return "Bob";
    if ((n & (n - 1)) == 0 && ((int)log2(n) % 2 != 0)) return "Bob"; 
    return "Alice";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed);

    int T = 1;
    cin >> T;
    while (T--) {
        cout << solve() << endl;
    }
    return 0;
}