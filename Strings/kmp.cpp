// https://www.youtube.com/watch?v=nJbNe0Yzjhw

#include <bits/stdc++.h>
using namespace std;

int kmp(string pat, string str) {

    int n = str.size(), m = pat.size();

    vector<int> lps(m);
    lps[0] = 0;
    for (int i = 1; i < m; i++) {

        int l = lps[i - 1];
        while (l > 0 && pat[l] != pat[i]) l = lps[l - 1];
        if (pat[l] == pat[i]) l++;
        lps[i] = l;
    }
    int prev = 0;
    vector<bool> match(n, false);
    for (int i = 0; i < n; i++) {

        int l = prev;
        while (l > 0 && pat[l] != str[i]) l = lps[l - 1];
        if (pat[l] == str[i]) l++;
        if (l == m) match[i - m + 1] = true;
        prev = l;
    }
    return count(match.begin(), match.end(), true);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    string pat, str;
    cin >> pat >> str;
    cout << kmp(pat, str);
}
