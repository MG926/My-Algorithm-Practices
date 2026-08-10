class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        """思路：排序后双指针，第一层时间复杂度O(N)，第二层和第三层相向执行，复杂度为O(N)，总的复杂度为O(N2)"""
        nums.sort()
        n = len(nums)
        ans = []
        for i in range(n-2):
            if(i>0 and nums[i]==nums[i-1]): continue
            kidx = n-1
            for j in range(i+1,n-1):
                if(j>i+1 and nums[j] == nums[j-1]): continue
                tar = -nums[i]-nums[j]
                while(kidx>j and nums[kidx]>tar):
                    kidx -= 1
                if(kidx <= j): break
                if(nums[kidx] == tar): ans.append([nums[i],nums[j],nums[kidx]])
        return ans
                
