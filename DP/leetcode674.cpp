#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        //动态规划方程为首尾
        int n=s.length();
        vector<vector<bool>> dp(n,vector<bool>(n));
        for(int i=0;i<n;i++){
            dp[i][i] = true;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(i==j+1 && s[i]==s[j]) dp[j][i] = true;
                if(!dp[j][i]) continue;
                if(j>0 && i<n-1 && s[i+1]==s[j-1]){
                    dp[j-1][i+1] = true;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(dp[i][j]) ans++;
            }
        }
        return ans;
    }
};