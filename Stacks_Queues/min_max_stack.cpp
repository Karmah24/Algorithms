#include <bits/stdc++.h>
using namespace std;
class MinStack {
public:
    stack<int> stack;
    int min;
    void push(int x) {
        if (stack.empty()) {
            min = x;
            stack.push(x); 
        }
        else {
            if (x < min) {
                stack.push(2LL * x - min);
                min = x;
            }
            else stack.push(x);
        }
    }
    
    void pop() {
        if (stack.top() < min) {
            min = (2LL * min - stack.top());
            stack.pop();
        }
        else stack.pop();
    }
    
    int top() {
        if (stack.top() < min) {
            return (2LL * min - stack.top());
        }
        else return stack.top();
    }
    
    int getMin() {
        return min;
    }
};

int main() {
    MinStack minStack;
    minStack.push(2147483646);
    minStack.push(2147483646);
    minStack.push(2147483647);
    cout << minStack.top() << ' ';
    minStack.pop();
    cout << minStack.getMin() << ' ';
    minStack.pop();
    cout << minStack.getMin() << ' ';
    minStack.pop();
    minStack.push(2147483647);
    cout << minStack.top() << ' ';
    cout << minStack.getMin() << ' ';
    minStack.push(-2147483648);
    cout << minStack.top() << ' ';
    cout << minStack.getMin() << ' ';
    minStack.pop();
    cout << minStack.getMin() << ' ';

}