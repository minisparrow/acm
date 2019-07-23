class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        length = len(nums)
        for i in range(0,length):
            for j in range(length-1,i,-1):
                adder = nums[i] + nums[j]
                if adder == target:
                    return i,j

sln = Solution()

nums = [3,2,4]
target = 6
i,j = sln.twoSum(nums,target)
print(i,j)
