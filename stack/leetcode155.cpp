#include <iostream>
#include <stack>
using namespace std;
class MinStack {
private:
    stack<int> my_stack,min_stack;
public:
    MinStack() {}
    
    void push(int value) {
        my_stack.push(value);
        if(min_stack.empty()) min_stack.push(value);
        else min_stack.push(min(value,min_stack.top()));
    }
    
    void pop() {
        my_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return my_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */