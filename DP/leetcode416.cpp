#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum%2) return false;
        vector<bool> dp(sum+1,false);
        dp[0] = true;
        for(int i=0;i<n;i++){
            vector<bool> dp1(sum+1,false);
            for(int j=0;j<sum+1;j++){
                if(dp[j]){
                    dp1[j] = true;
                    dp1[j+nums[i]] = true;
                }
            }
            dp = dp1;
        }
        sum /= 2;
        return dp[sum];
    }
};