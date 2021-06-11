#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> nextLarger(vector<ll> arr, int n) {
    
    stack<ll> s;
    s.push(arr[n - 1]);
    vector<ll> res(n);

    res[n - 1] = -1;
    for (int i = n - 2; i >= 0; i--) {
        
        while (!s.empty() && s.top() <= arr[i]) s.pop();
        if (s.empty()) res[i] = -1;
        else res[i] = s.top();

        s.push(arr[i]);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (ll& e: nextLarger(arr, n)) cout << e << " ";
}