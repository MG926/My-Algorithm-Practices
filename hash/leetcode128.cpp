#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //利用哈希表的O(1)查询，并且采用前向查询，节省时间开销
        unordered_set<int> num_set(nums.begin(),nums.end());
        int ans=0;
        for(auto i=num_set.begin();i!=num_set.end();i++){
            if(num_set.count(*i-1)) continue;
            int j=*i,cnt=0;
            while(num_set.count(j)){
                cnt++;
                j++;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};