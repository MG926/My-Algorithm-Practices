class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        """思路：利用字符串切片模拟"""
        n1 = len(haystack)
        n2 = len(needle)
        if(n2>n1): return -1
        for i in range(n1-n2+1):
            now_word = haystack[i:i+n2]
            if(now_word==needle): return i
        return -1
