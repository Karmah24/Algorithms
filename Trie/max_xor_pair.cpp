#include <bits/stdc++.h>
using namespace std;

const int SIZE = 31;

struct TrieNode {
    TrieNode* child[2];
    TrieNode() {
        child[0] = child[1] = nullptr;
    }
};
class Trie {
    TrieNode *root = new TrieNode();
public:
    void insert(int num) {
        TrieNode *curr = root;
        for (int i = SIZE; i >= 0; i--) {

            bool bit = num & (1 << i);
            if (!curr->child[bit]) curr->child[bit] = new TrieNode();
            curr = curr->child[bit];
        }
    }
    int query(int num) {
        TrieNode *curr = root;
        int res = 0;
        for (int i = SIZE; i >= 0; i--) {

            res <<= 1;
            bool bit = num & (1 << i);
            if (curr->child[1 - bit]) {
                res |= 1;
                curr = curr->child[1 - bit];
            }
            else {
                res |= 0;
                curr = curr->child[bit];
            }
        }
        return res;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& arr) {

        int res = INT_MIN;
        Trie trie;
        for (int e: arr) {
            trie.insert(e);
            res = max(res, trie.query(e));
        }
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    cout << obj.findMaximumXOR(arr);
}