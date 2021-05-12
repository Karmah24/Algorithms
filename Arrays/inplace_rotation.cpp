#include<bits/stdc++.h>

using namespace std;

#define gc getchar_unlocked
#define loop(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define all(x) x.begin(), x.end()
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}
const int mod = int(1e9 + 7);
const int N = 3e5, M = N;
//=======================

vi graph[N];
bool vis[N] = { };
int arr[N];

void solve(int n, int **mat) {
    loop (i, n / 2) {
        int k = n - 2*i - 1;
        for (int j = 0; j < k; j++) {

            int buff1 = mat[i][i + j], buff2 = mat[i + j][n - 1 - i];
            mat[i + j][n - 1 - i] = buff1;
            buff1 = buff2;
            buff2 = mat[n - 1- i][n - 1 - i - j];
            mat[n - 1 - i][n - 1 - i - j] = buff1;
            buff1 = buff2;
            buff2 = mat[n - 1 - i - j][i];
            mat[n - 1 - i - j][i] = buff1;
            buff1 = buff2;
            mat[i][i + j] = buff2;
        }
    }
    loop (i, n) loop (j, n) cout << mat[i][j] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int **mat = new int *[n];
            loop (i, n)
                mat[i] = new int[n];
        loop (i, n) loop (j, n) cin >> mat[i][j];

        solve(n, mat);

        loop (i, n)
            delete [] mat[i];
        delete [] mat;
    }

    return 0;
}