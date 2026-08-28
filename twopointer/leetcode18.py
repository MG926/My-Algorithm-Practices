class Solution:
    def fourSum(self, nums: list[int], target: int) -> list[list[int]]:
        """思路：与leetcode15三数之和思想一致，时间复杂度为O(N**3)"""
        n = len(nums)
        nums.sort()
        ans = []
        for i in range(n-3):
            if(i>0 and nums[i]==nums[i-1]): continue
            for j in range(i+1,n-2):
                if(j>i+1 and nums[j]==nums[j-1]): continue
                m = n-1
                for k in range(j+1,n-1):
                    if(k>j+1 and nums[k]==nums[k-1]): continue
                    tar = target-nums[i]-nums[j]-nums[k]
                    while(m>k and nums[m]>tar):
                        m -= 1
                    if(m<=k):
                        break
                    if(nums[m]==tar):
                        ans.append([nums[i],nums[j],nums[k],nums[m]])
        return ans