class Solution:
    def threeSumClosest(self, nums: list[int], target: int) -> int:
        """思路：与leetcode15思路一样，采用双指针查询"""
        ans = 0
        ans_m = 10000000
        nums.sort()
        n = len(nums)
        for i in range(n-2):
            k = n-1
            for j in range(i+1,n-1):
                num_s = nums[i]+nums[j]+nums[k]
                while(k>j+1 and num_s>target):
                    k -= 1
                    num_s = nums[i]+nums[j]+nums[k]
                if(k == j): break
                if(num_s == target): return target
                if(k!=n-1):
                    nums1 = nums[i]+nums[j]+nums[k+1]
                    nums1_m = nums1-target
                    if(abs(nums1_m)<abs(ans_m)):
                        ans = nums1
                        ans_m = nums1_m
                nums_m = num_s-target
                if(abs(nums_m)<abs(ans_m)):
                    ans = num_s
                    ans_m = nums_m
                
        return ans
s = Solution()
print(s.threeSumClosest([-2,-1,1,4],0))