#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Job {
    int st, fin, profit;
    bool operator <(const Job &other) {
        return fin < other.fin;
    }
};

int lowerBound(vector<Job> &jobs, int i) {

    int l = 0, r = i - 1, x = jobs[i].st;
    int res = i;
    while (l <= r) {
        int mid = (l + r) / 2;

        if (jobs[mid].fin < x) l = mid + 1;
        else {
            res = mid;
            r = mid - 1;
        }
    }
    return res;
}
ll maxEarning(int n, vector<Job> &jobs) {

    sort(jobs.begin(), jobs.end());
    ll dp[n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {

        int prev = lowerBound(jobs, i);
        dp[i + 1] = max(dp[i], dp[prev] + jobs[i].profit);
    }
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<Job> jobs(n);
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].st >> jobs[i].fin >> jobs[i].profit;
    }
    cout << maxEarning(n, jobs);
    return 0;
}