#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        vector<pair<int,int>> cnt(freq.begin(),freq.end());
        sort(cnt.begin(),cnt.end(),[](const pair<int,int>& u, const pair<int,int>& v){
            return u.second>v.second;
        });
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(cnt[i].first);
        }
        return ans;
    }
};