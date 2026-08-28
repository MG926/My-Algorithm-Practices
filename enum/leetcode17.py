class Solution:
    def letterCombinations(self, digits: str) -> list[str]:
        """思路：字典枚举"""
        dic = {
            "2": ["a","b","c"],
            "3": ["d","e","f"],
            "4": ["g","h","i"],
            "5": ["j","k","l"],
            "6": ["m","n","o"],
            "7": ["p","q","r","s"],
            "8": ["t","u","v"],
            "9": ["w","x","y","z"],
        }
        ans = [""]
        n = len(digits)
        k = 0
        while(k<n):
            if(len(ans[0])!=k): 
                k += 1
                continue
            word = ans.pop(0)
            for next_word in dic[digits[k]]:
                now_word = word+next_word
                ans.append(now_word)
        return ans
            