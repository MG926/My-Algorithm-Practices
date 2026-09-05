#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //双指针头尾遍历，跳过下标位置元素乘积
        int n=nums.size();
        int left=0,right=n-1,lp=1,rp=1;
        vector<int> ans(n,1);
        while(left<n && right>=0){
            ans[left] *= lp;
            ans[right] *= rp;
            lp *= nums[left++];
            rp *= nums[right--];
        }
        return ans;
    }
};