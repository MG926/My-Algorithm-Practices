#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //采用动态规划来节省时间
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0') dp[i+1][j+1] = 0;
                else{
                    int l=dp[i+1][j],u=dp[i][j+1],r=dp[i][j];
                    if(l && u){
                        if(l>u){
                            dp[i+1][j+1] = min(u,r)+1;
                        }else{
                            dp[i+1][j+1] = min(l,r)+1;
                        }
                    }else{
                        dp[i+1][j+1] = 1;
                    }
                }
            }
        }
        int ans=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                ans = max(dp[i][j],ans);
            }
        }
        return ans*ans;
    }
    
};

int main()
{
    Solution s;
    vector<vector<char>> matrix={ {'1','1','1','1','0'}, {'1','1','1','1','0'}, {'1','1','1','1','1'}, {'1','1','1','1','1'}, {'0','0','1','1','1'} };
    s.maximalSquare(matrix);
    return 0;
}