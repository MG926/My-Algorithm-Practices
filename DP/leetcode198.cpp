#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        //动态规划
        int n=nums.size();
        vector<int> dp(n+2);
        for(int i=0;i<n;i++){
            dp[i+2] = max(dp[i+1],dp[i]+nums[i]);
        }
        return max(dp[n+1],dp[n]);
    }
};