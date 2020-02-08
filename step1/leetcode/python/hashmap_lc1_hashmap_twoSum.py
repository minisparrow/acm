# leetcode1 https://leetcode-cn.com/problems/two-sum/


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
        hashmap = {}
        for idx, num in enumerate(nums):
            gap = target - num
            if gap in hashmap:
                return hashmap[gap],idx
            hashmap[num] = idx
        return None


def test(nums,target):
    sln = Solution()
    i,j = sln.twoSum_hash(nums,target)
    print(nums,target,"=>",i,j)


if __name__ == "__main__":
    nums = [2,5,5,11]
    target = 10
    test(nums,target)

    nums = [2,5,11]
    target = 7
    test(nums,target)
