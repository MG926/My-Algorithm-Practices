#include <vector>
#include <unordered_set>
#include <string>
using namespace std;
class Solution {
private:
    unordered_set<string> ans;
public:
    vector<string> removeInvalidParentheses(string s) {
        int n=s.length();
        int left_num=0,right_num=0;
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                if(left_num==0) right_num++;
                else left_num--; 
            }else if(s[i]=='('){
                left_num++;
            }
        }
        dfs(s,0,left_num,right_num);
        vector<string> ret;
        for(auto str:ans){
            ret.push_back(str);
        }
        return ret;
    }
    
    void dfs(string s, int start, int left_num, int right_num){
        if(!left_num && !right_num){
            if(isvalid(s) && ans.find(s)==ans.end()){
                ans.insert(s);
            }
            return;
        }
        for(int i=start;i<s.length();i++){
            if(i!=start && s[i]==s[i-1]) continue;
            if(left_num+right_num>s.length()-i) return;
            if(s[i]=='(' && left_num){
                dfs(s.substr(0,i)+s.substr(i+1),i,left_num-1,right_num);
            }
            if(s[i]==')' && right_num){
                dfs(s.substr(0,i)+s.substr(i+1),i,left_num,right_num-1);
            }
        }
    }

    bool isvalid(string s){
        int n=s.length();
        int left_num=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') left_num++;
            else if(s[i]==')') left_num--;
            if(left_num==-1) return false;
        }
        if(left_num==0) return true;
        return false;
    }
};