#include <bits/stdc++.h>
using namespace std;

class TextEditor {
public:
    deque<char> after_cursor, before_cursor;

    TextEditor() {}

    void addText(string text) {
        for (auto &ch: text) before_cursor.push_back(ch);
    }

    int deleteText(int k) {
        int deleted = 0;
        while (!before_cursor.empty() && k--) {
            deleted++;
            before_cursor.pop_back();
        }
        return deleted;
    }

    string recall() {
        string recall = "";
        int mx_recall = 10;
        int i = before_cursor.size() - 1;
        while (i >= 0 && mx_recall--) {
            recall.push_back(before_cursor[i--]);
        }
        reverse(recall.begin(), recall.end());
        return recall;
    }

    string cursorLeft(int k) {
        while (!before_cursor.empty() && k--) {
            after_cursor.push_front(before_cursor.back());
            before_cursor.pop_back();
        }
        return recall();
    }

    string cursorRight(int k) {
        while (!after_cursor.empty() && k--) {
            before_cursor.push_back(after_cursor.front());
            after_cursor.pop_front();
        }
        return recall();
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    TextEditor editor;
    editor.addText("leetcode");
    cout << editor.deleteText(4) << '\n';
    editor.addText("practice");
    cout << editor.cursorRight(3) << '\n';
    cout << editor.cursorLeft(8) << '\n';
    cout << editor.deleteText(10) << '\n';
    cout << editor.cursorLeft(2) << '\n';
    cout << editor.cursorRight(6) << '\n';

    return 0;
}