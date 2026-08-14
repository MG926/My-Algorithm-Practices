class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        """思路：官方跑题有问题"""
        if(not dividend): return 0
        minus = (dividend>0)^(divisor>0)
        dividend = abs(dividend)
        divisor = abs(divisor)
        ans = 0
        now_divisor = divisor
        k_lists = []
        divisor_lists = []
        k = 1
        while(dividend>=now_divisor):
            if(now_divisor>dividend): break
            k_lists.append(k)
            k += k
            divisor_lists.append(now_divisor)
            now_divisor += now_divisor
        while(dividend>=divisor):
            k = k_lists.pop()
            now_divisor = divisor_lists.pop()
            if(dividend>now_divisor):
                ans += k
                dividend -= now_divisor
            elif(dividend==now_divisor):
                ans += k
                break
        return -ans if minus else ans
