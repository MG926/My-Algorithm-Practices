class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        """思路：按照题意双指针k表示新数组大小，idx遍历原数组即可"""
        k = 1
        idx = 1
        n = len(nums)
        while(idx<n):
            while(idx<n and nums[idx-1]==nums[idx]): idx += 1
            if(idx==n):break
            nums[k] = nums[idx]
            k += 1
            idx += 1
        return k