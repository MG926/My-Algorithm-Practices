class Solution:
    def romanToInt(self, s: str) -> int:
        """思路：利用字典进行模拟数学计算"""
        dic = {"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}
        ans = 0
        k = 0
        n = len(s)
        while(k<n):
            if(k!=n-1 and dic[s[k]]<dic[s[k+1]]):
                ans += dic[s[k+1]]-dic[s[k]]
                k += 2
            else:
                ans += dic[s[k]]
                k += 1
        return ans