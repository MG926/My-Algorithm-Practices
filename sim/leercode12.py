class Solution:
    def intToRoman(self, num: int) -> str:
        """思路：按位判断转化"""
        ans = ""
        if(num>=1000):
            tmp = num//1000
            ans += "M"*tmp
            num = num%1000
        if(num>=100):
            tmp = num//100
            if(tmp==4):
                ans += "CD"
            elif(tmp==9):
                ans += "CM"
            elif(tmp<4):
                ans += "C"*tmp
            else:
                ans += "D"
                tmp -= 5
                ans += "C"*tmp
            num %= 100
        if(num>=10):
            tmp = num//10
            if(tmp==4):
                ans += "XL"
            elif(tmp==9):
                ans += "XC"
            elif(tmp<4):
                ans += "X"*tmp
            else:
                ans += "L"
                tmp -= 5
                ans += "X"*tmp
            num %= 10
        if(num>=1):
            if(num == 4):
                ans += "IV"
            elif(num == 9):
                ans += "IX"
            elif(num<4):
                ans += "I"*num
            else:
                ans += "V"
                num -=5
                ans += "I"*num
        return ans