#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<bool> dp(n+1);
        dp[0] = 1;
        for(int i=1;i<n+1;i++){
            for(int j=0;j<i;j++){
                dp[i] = dp[j]&&check(j,i,s,wordDict);
                if(dp[i]) break;
            }
        }
        return dp[n];
    }
    bool check(int x, int y, string s, vector<string>& wordDict){
        string tmp=s.substr(x,y-x);
        int n=wordDict.size();
        for(int i=0;i<n;i++){
            if(wordDict[i]==tmp) return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    string s="leetcode";
    vector<string> word={"leet","code"};
    sol.wordBreak(s,word);
    return 0;
}