#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
typedef pair<int, int>	pii;
typedef vector<int>		vi;
typedef vector<pii>		vpii;
typedef vector<vi>		vvi;
//=======================

class Solution{
public:
	int search(string pat, string txt) {
	    
	    int n = txt.size(), k = pat.size();
	    map<char, int> patMap;
	    map<char, int> foundMap;
	    int unique = 0;
	    for (char ch: pat) {
	        patMap[ch]++;
	        if (patMap[ch] == 1) unique++;
	    }
	    int found = 0, res = 0;
	    int i = 0, j = 0;
	    
	    while (j < k) {
	        if (++foundMap[txt[j]] == patMap[txt[j]]) found++;
	        j++;
	    }
	    if (found == unique) res++;
	    
	    while (j < n) {
	        if (foundMap[txt[i]]-- == patMap[txt[i]]) found--;
	        i++;
	        if (++foundMap[txt[j]] == patMap[txt[j]]) found++;
	        j++;
	        if (found == unique) res++;
	    }
	    return res;
	}

};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string txt, pat;
    cin >> txt >> pat;
    Solution obj;
    cout << obj.search(pat, txt);
}
