#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //快排思想
        int n=nums.size();
        return quicksort(nums,0,n-1,n-k);
    }
    int quicksort(vector<int>& nums, int l, int r, int k){
        if(l==r) return nums[k];
        int base=nums[l],i=l-1,j=r+1;
        while(i<j){
            do i++;while(nums[i]<base);
            do j--;while(nums[j]>base);
            if(i<j) swap(nums[i],nums[j]);
        }
        if(k<=j) return quicksort(nums,l,j,k);
        else return quicksort(nums,j+1,r,k);
    }
};