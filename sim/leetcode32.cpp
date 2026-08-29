#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        //本题采用模拟和栈的思维
        stack<int> my_stack;
        int n = size(s), ans = 0, f = -1;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                my_stack.push(i);
            }else{
                if(!my_stack.empty()){
                    my_stack.pop();
                    if(!my_stack.empty()){
                        ans = max(ans,i-my_stack.top());
                    }else{
                        ans = max(ans,i-f);
                    }
                }else{
                    f = i;
                }
            }
        }
        return ans;
    }
};