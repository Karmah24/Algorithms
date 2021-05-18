#include <bits/stdc++.h>
using namespace std;

struct Node {
    int freq;
    char ch;
    Node *left = nullptr, *right = nullptr;
    Node(int freq, char ch): freq(freq), ch(ch) {}
};
struct compare {
    bool operator()(Node *a, Node *b) {
        return a->freq > b->freq;
    }
};

class Solution {
    Node* merge(Node *a, Node *b) {
        Node *root = new Node(a->freq + b->freq, '#');
        root->left = a->freq <= b->freq ? a : b;
        root->right = a->freq <= b->freq ? b : a;
        return root;
    }
    void traverse(Node *root, vector<string>& res, string code) {
        if (!root->left && !root->right) {
            res.push_back(code);
            return;
        }
        if (root->left) traverse(root->left, res, code + "0");
        traverse(root->right, res, code + "1");
    }
public:
	vector<string> huffmanCodes(string& str, vector<int>& freq, int n) {
	    
        priority_queue<Node*, vector<Node*>, compare> nodes;
        for (int i = 0; i < n; i++) nodes.push(new Node(freq[i], str[i]));
        
        while (nodes.size() != 1) {
            Node *min1 = nodes.top();
            nodes.pop();
            Node *min2 = nodes.top();
            nodes.pop();
            nodes.push(merge(min1, min2));
        }
        Node *root = nodes.top();
        vector<string> res;
        traverse(root, res, "");
        return res;
	}
};


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> freq(n);
    for (int i = 0; i < n; i++) cin >> freq[i];
    cin.ignore();
    string str;
    cin >> str;
    Solution obj;
    for (string s: obj.huffmanCodes(str, freq, n)) cout << s << ' ';
}