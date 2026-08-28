class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        """思路：和leetcode26一样"""
        k = 0
        idx = 0
        n = len(nums)
        while(idx<n):
            while(idx<n and nums[idx]==val): idx += 1
            if(idx==n): break
            nums[k] = nums[idx]
            k += 1
            idx += 1
        return k