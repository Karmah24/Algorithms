#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
#define ll long long
//=======================

class Solution {
    ll merge(ll arr[], int l, int h) {

        if (l == h) return 0;

        int mid = l + (h - l) / 2;
        ll inv = merge(arr, l, mid) + merge(arr, mid + 1, h);

        ll temp[h - l + 1];
        int k = h - l;
        int i = mid, j = h;

        while (i != l - 1 && j != mid) {
            if (arr[i] > arr[j]) {
                inv += j - mid;
                temp[k--] = arr[i--];
            }
            else {
                temp[k--] = arr[j--];
            }
        }
        while (i != l - 1) {
            temp[k--] = arr[i--];
        }
        while (j != mid) {
            temp[k--] = arr[j--];
        }

        int x = 0, itr = l;
        while (itr <= h) {
            arr[itr++] = temp[x++];
        }
        return inv;
    }
public:
    ll inversionCount(ll arr[], ll N) {
        return merge(arr, 0, N - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    ll n;
    cin >> n;
    ll arr[n];
    loop (i, n) cin >> arr[i];
    Solution obj;
    cout << obj.inversionCount(arr, n);
}
