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
    def twoSum_hash(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        mapping = {}
        length = len(nums)
        for i in range(0,length):
            mapping[nums[i]] = i

        for i in range(0,length):
            gap = target - nums[i]
            print(mapping[gap])
            if mapping[gap]:
                return i,mapping[gap]


sln = Solution()

nums = [2,5,5,11]
target = 10
i,j = sln.twoSum_hash(nums,target)
print(i,j)
