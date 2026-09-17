#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int> val(n+2,1);
        for(int i=1;i<n+1;i++){
            val[i] = nums[i-1];
        }
        vector<vector<int>> rec(n+2,vector<int>(n+2));
        for(int l=3;l<=n+2;l++){
            for(int i=0;i+l<=n+2;i++){
                int j=i+l-1;
                for(int k=i+1;k<j;k++){
                    rec[i][j] = max(rec[i][j],rec[i][k]+val[i]*val[k]*val[j]+rec[k][j]);
                }
            }
        }
        return rec[0][n+1];
    }
};