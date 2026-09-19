#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp;
        for(int i=0;i<n;i++){
            int k=dp.size();
            if(!k) dp.push_back(nums[i]);
            else{
                if(dp[k-1]<nums[i]) dp.push_back(nums[i]);
                else if(dp[k-1]>nums[i]){
                    int idx = binarySearch(dp,nums[i]);
                    dp[idx] = nums[i];
                }
            }
        }
        return dp.size();
    }
    int binarySearch(vector<int>& list, int target){
        int l=0,r=list.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(list[mid]<target) l = mid+1;
            else r = mid-1;
        }
        return l;
    }
};
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         int ans=1;
//         vector<int> dp(n,1);
//         for(int i=0;i<n;i++){
//             for(int j=0;j<i;j++){
//                 if(nums[i]>nums[j]) dp[i] = max(dp[i],dp[j]+1);
//                 ans = max(ans,dp[i]);
//             }
//         }
//         return ans;
//     }
// };