#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        vector<int> dp(amount+1,-1);
        dp[0] = 0;
        int n = coins.size();
        for(int i=1;i<=amount;i++){
            for(int j=0;j<n;j++){
                int last = i-coins[j];
                if(last>=0 && dp[last]!=-1){
                    if(dp[i]==-1) dp[i] = dp[last]+1;
                    else dp[i] = min(dp[i],dp[last]+1);
                }
            }
        }
        return dp[amount];
    }
};