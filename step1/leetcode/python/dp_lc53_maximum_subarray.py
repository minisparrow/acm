#-*- coding=utf-8 -*-
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #idea:
        #f[n] = f[n-1] + n if n > 0, 选择n并加上
        #f[n] =          n if n < 0, 选择n并抛弃原来前面的数（因为是求连续的子序列）
        
        # 边界问题:
        # f[0] = 0
        
        f = len(nums)*[0]
        for i in range(0,len(nums)):
            if i == 0:
                f[i] = nums[i]
            A = f[i-1] + nums[i]
            B = nums[i]
            f[i] = max(A,B)
        return max(f)

        
def test_maxSubArray():
    input_array = [-2,1,-3,4,-1,2,1,-5,4]
    sln = Solution()
    ans = sln.maxSubArray(input_array)
    print(ans)

if __name__ == "__main__":
    test_maxSubArray()
