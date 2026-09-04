#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //采用dfs直接修改grid数组就行
        int m=grid.size(),n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,j,i);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& grid, int x, int y){
        int m=grid.size(),n=grid[0].size(); 
        grid[y][x] = '0';
        if(x-1>=0 && grid[y][x-1]=='1') dfs(grid,x-1,y);
        if(y-1>=0 && grid[y-1][x]=='1') dfs(grid,x,y-1);
        if(x+1<n && grid[y][x+1]=='1') dfs(grid,x+1,y);
        if(y+1<m && grid[y+1][x]=='1') dfs(grid,x,y+1);
    }
};

int main()
{
    Solution s;
    vector<vector<char>> grid={
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    s.numIslands(grid);
    return 0;
}