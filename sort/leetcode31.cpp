#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                idx = i;
                break;
            }
        }
        bbsort(nums,idx,n-1);
        if(idx==0) return;
        for(int i=idx;i<n;i++){
            if(nums[idx-1]<nums[i]){
                swap(nums,idx-1,i);
                break;
            }
        }
    }
    void swap(vector<int>& nums, int l, int r){
        int tmp = nums[l];
        nums[l] = nums[r];
        nums[r] = tmp;
    }
    void bbsort(vector<int>& nums, int start, int end){
        int f = 1;
        for(int i=start;i<end;i++){
            for(int j=end;j>i;j--){
                if(nums[j]<nums[j-1]){
                    f = 0;
                    swap(nums,j-1,j);   
                }
            }
            if(f) break;           
        }
    }
};
int main()
{
    Solution s;
    vector<int> nums={5,4,7,5,3,2};
    s.nextPermutation(nums);
    for(auto num:nums){
        cout<<num;
    }
    return 0;
}