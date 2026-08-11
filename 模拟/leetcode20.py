class Solution:
    def isValid(self, s: str) -> bool:
        """思路：简单的栈操作"""
        stack = []
        k = 0
        n = len(s)
        dic = {
            '(':')',
            '{':'}',
            '[':']'
        }
        while(k<n):
            now_s = s[k]
            if(now_s=='(' or now_s=='[' or now_s=='{'): stack.append(now_s)
            else:
                if(not len(stack)): return False
                last_s = stack.pop()
                if(dic[last_s]!=now_s): return False
            k += 1
        if(stack): return False
        return True