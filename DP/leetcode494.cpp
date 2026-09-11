#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    int ans;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int num:nums) sum += num;
        int minus=sum-target;
        if(minus<0 || minus%2) return 0;
        minus = minus/2;
        int n=nums.size();
        vector<int> dp1(2000);
        dp1[0] += 1;
        for(int num:nums){
            for(int j=minus;j>=num;j--){
                dp1[j] += dp1[j-num];
            }
        }
        return dp1[minus];
    }
    
};
// class Solution {
// private:
//     int ans;
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         ans = 0;
//         dfs(nums,0,target);
//         return ans;
//     }
//     void dfs(vector<int>& nums, int idx, int cnt){
//         if(idx==nums.size()){
//             if(cnt==0) ans++;
//             return;
//         }
//         int cnt1=cnt+nums[idx],cnt2=cnt-nums[idx];
//         idx++;
//         dfs(nums,idx,cnt1);
//         dfs(nums,idx,cnt2);
//     }
// };