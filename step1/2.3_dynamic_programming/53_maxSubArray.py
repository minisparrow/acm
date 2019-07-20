class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        f = [0]*len(nums)
        for i in range(0,len(nums)):

            if i == 0:
                f[i] = nums[i]
            else:
                A = f[i-1] + nums[i]
                B = nums[i]
                f[i] = max(A,B)
            
        return max(f)


nums = [-2,1,-3,4,-1,2,1,-5,4]
sln = Solution()
res = sln.maxSubArray(nums)
print(res)
