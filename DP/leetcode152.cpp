#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //动态规划
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> min_nums(n),max_nums(n);
        min_nums[0] = nums[0];
        max_nums[0] = nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++){
            int n1=max_nums[i-1]*nums[i],n2=min_nums[i-1]*nums[i];
            if(n1>n2){
                if(n1>nums[i]){
                    max_nums[i] = n1;
                    if(nums[i]<n2) min_nums[i] = nums[i];
                    else min_nums[i] = n2;
                }else{
                    max_nums[i] = nums[i];
                    min_nums[i] = n2;
                }
            }else{
                if(n2>nums[i]){
                    max_nums[i] = n2;
                    if(n1<nums[i]) min_nums[i] = n1;
                    else min_nums[i] = nums[i];
                }else{
                    max_nums[i] = nums[i];
                    min_nums[i] = n1;
                }
            }
            ans = max(ans,max_nums[i]);
        }
        
        return ans;

    }
};