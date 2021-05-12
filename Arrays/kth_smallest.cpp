#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for (int i = 0; i < n; i++)
const int N = 3e5, M = N;
//=======================
int arr[N];

int partition(int r, int p) {
    int i = r, k = arr[r];
    for (int j = r + 1; j < p; j++) {
        if (arr[j] < k) {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i], arr[r]);
    return i;
}
int rand_partition(int r, int p) {
    int i = r + (rand() % (p - r));
    swap(arr[i], arr[r]);
    return partition(r, p);
}
void find(int r, int p, int k) {
    if (r <= p) {
        int q = rand_partition(r, p);
        if (q == k)
            cout << arr[q] << endl;
        else if (q < k) find(q + 1, p, k);
        else find(r, q, k);
    }
}
void solve() {
    int n, k;
    cin >> n >> k;
    loop (i, n)
        cin >> arr[i];
    find(0, n, k - 1);    
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}