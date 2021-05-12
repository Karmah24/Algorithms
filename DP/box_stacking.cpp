#include <bits/stdc++.h>
using namespace std;

#define fori(i, n) for (int i = 0; i < n; i++)
//=======================

struct box {
    int h, l, w;
    box(int h, int l, int w) : h(h), l(l), w(w) {}
};

class Solution {
public:
    int lis(vector<box>& boxes) {
        int n = boxes.size();
        vector<int> res(n);
        int res_max = 0;
        fori (i, n) res[i] = boxes[i].h;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (boxes[j].l < boxes[i].l && boxes[j].w < boxes[i].w 
                    && res[i] < res[j] + boxes[i].h) {
                    res[i] = res[j] + boxes[i].h;
                    res_max = max(res_max, res[i]);
                }
            }
        }
        return res_max;
    }
    int maxHeight(int height[],int width[],int length[],int n) {
        vector<box> boxes;
        fori (i, n) {
            boxes.push_back(box(height[i], min(width[i], length[i]), max(width[i], length[i])));
            boxes.push_back(box(width[i], min(height[i], length[i]), max(height[i], length[i])));
            boxes.push_back(box(length[i], min(width[i], height[i]), max(width[i], height[i])));
        }
        auto comp = [](box a, box b) {
            return a.l * a.w < b.l * b.w;
        };
        sort(boxes.begin(), boxes.end(), comp);
        return lis(boxes);
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
    int n;
    cin >> n;
    int height[n], width[n], length[n];
    fori (i, n) cin >> height[i];
    fori (i, n) cin >> width[i];
    fori (i, n) cin >> length[i];
    Solution obj;
    cout << obj.maxHeight(height, width, length, n) << endl;
}