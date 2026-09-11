#include <iostream>
using namespace std;
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z=x^y,cnt=1;
        if(z==0) return 0;
        while(cnt<=z){
            cnt <<= 1;
        }
        int ans=0;
        while(z){
            while(cnt>z) cnt >>= 1;
            z -= cnt;
            ans++;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    s.hammingDistance(680142203,1111953568);
    return 0;
}