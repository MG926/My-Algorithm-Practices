#include <iostream>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==0) return 0;
        int flag = (dividend>0)^(divisor>0);
        dividend = dividend>0?dividend:-dividend;
        divisor = divisor>0?divisor:-divisor;
        int ans = minus(dividend,divisor);
        return flag?-ans:ans;
    }
    int minus(int dividend, int divisor){
        int k = 0;
        int now_divisor = divisor;
        while(dividend>now_divisor){
            k++;
            now_divisor <<= 1;
        }
        int ret = 0;
        while(dividend>=divisor){
            if(dividend>now_divisor){
                ret += 2<<k;
                dividend -= now_divisor;
            }else if(dividend==now_divisor){
                ret += 2<<k;
                return ret;
            }
            k--;
            now_divisor >>= 1;
        }
        return ret;
    }
};
int main()
{
    Solution s;
    int ans = s.divide(10,3);
    cout << ans;
}
