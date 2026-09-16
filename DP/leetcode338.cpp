#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0) return {0};
        vector<int> two={1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536,131072};
        int k=0;
        vector<int> ans(n+1);
        ans[0] = 0;
        for(int i=1;i<n+1;i++){
            if(i==two[k+1]) k++;
            ans[i] = ans[i-two[k]]+1;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    sol.countBits(5);
}