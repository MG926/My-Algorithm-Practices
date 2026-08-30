#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //采用二分查找，根据左边界和右边界的需求定制判断标准
        if(nums.size()==0) return {-1,-1};
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]<target) l = mid+1;
            else r = mid-1;
        }
        vector<int> ans(2);
        if(l>=nums.size() || nums[l]!=target){
            ans[0] = -1;
            ans[1] = -1;
            return ans;
        }
        ans[0] = l;
        l = 0;
        r = nums.size()-1;
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]<=target) l = mid+1;
            else r = mid-1;
        }
        if(nums[l]==target) ans[1] = l;
        else ans[1] = l-1;
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums={5,7,7,8,8,10};
    s.searchRange(nums,8);
}