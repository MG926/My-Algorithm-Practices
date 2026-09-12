#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[nums[i]%n]<=n) nums[nums[i]%n] += n;
        }
        if(nums[0]<=n) ans.push_back(n);
        for(int i=1;i<n;i++){
            if(nums[i]<=n) ans.push_back(i);
        }
        return ans;
    }
};
// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         int n=nums.size();
//         unordered_set<int> hash(nums.begin(),nums.end());
//         vector<int> ans;
//         for(int i=1;i<n+1;i++){
//             if(!hash.count(i)) ans.push_back(i);
//         }
//         return ans;
//     }
// };