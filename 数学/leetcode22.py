class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        """思路：数学题，隔板原理，先固定左括号，然后右括号对应插入空挡，利用栈来操作"""
        ans = []
        stacks = [["",n]]
        k = 0
        while(k<n):
            next_stacks = []
            while(stacks):
                now_stack = stacks.pop()
                last_num = now_stack[1]
                now_ans = now_stack[0]
                if(last_num==0):
                    now_ans = "("*(n-k)+now_ans
                    ans.append(now_ans)
                    continue
                min_num = 0
                if(last_num+k==n): min_num = 1
                for i in range(last_num,min_num-1,-1):
                    next_ans = "("+")"*i+now_ans
                    next_num = last_num-i
                    next_stacks.append([next_ans,next_num])
            stacks = next_stacks
            k += 1
        while(stacks):
            now_stack = stacks.pop()
            ans.append(now_stack[0])
        return ans