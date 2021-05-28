#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Deque O(n)
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        vector<int> res;
        int n = arr.size(), i = 0, j = 0;
        deque<int> q;

        while (j < k) {
            if (q.empty() || arr[q.back()] > arr[j]) q.push_back(j++);
            else q.pop_back();
        }
        res.push_back(arr[q.front()]);
        while (j < n) {
            if (q.front() == i) q.pop_front();
            i++;
            while (!q.empty() && arr[q.back()] <= arr[j]) q.pop_back();
            q.push_back(j++);
            res.push_back(arr[q.front()]);
        }
        return res;
    }
    // Multiset O(n * log(k));
    vector<int> maxSlidingWindow1(vector<int>& arr, int k) {
        vector<int> res;
        int n = arr.size(), i = 0, j = 0;
        multiset<int, greater<int>> s;

        while (j < k) s.insert(arr[j++]);
        res.push_back(*s.begin());

        while (j < n) {
            s.erase(s.find(arr[i++]));
            s.insert(arr[j++]);
            res.push_back(*s.begin());
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    for (int e: obj.maxSlidingWindow(arr, k)) cout << e << " ";
}