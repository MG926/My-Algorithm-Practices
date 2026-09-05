#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //既然大于n/2，那么就直接计数就行
        int cnt=0,ans=-1,n=nums.size();
        for(int i=0;i<n;i++){
            if(cnt==0) ans = nums[i];
            if(nums[i]==ans) cnt++;
            else cnt--;
        }
        return ans;
    }
};