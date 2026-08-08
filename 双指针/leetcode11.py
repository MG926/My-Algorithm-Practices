class Solution:
    def maxArea(self, height: List[int]) -> int:
        """思路：双指针，由于隔板往中间靠拢，高的移动不如矮的移动，所以选择矮的夹板向内侧移动
           时间复杂度为O(n)，空间复杂度为O(1)"""
        n = len(height)
        ans = 0
        left = 0
        right = n-1
        while(left<right):
            ans = max(ans,(right-left)*min(height[right],height[left]))
            if(height[right]>height[left]): left += 1
            else: right -= 1
        return ans