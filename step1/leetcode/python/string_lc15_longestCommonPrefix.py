# -*- coding:utf-8 -*-
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        # 取出第一个元素
        # 取出第一个元素的i位置字符， 与第j个元素的第i个字符相比, 若相等，i+1. 若不等，返回i
        if len(strs) == 0: 
            return ""
        elif len(strs) == 1:
            return strs[0]

        idx = 0
        minl = min([len(s) for s in strs ])
        while idx < minl:
            for i in range(1,len(strs)):
                if strs[i][idx] != strs[i-1][idx]:
                   return strs[0][0:idx]
            idx += 1
        return strs[0][0:idx]

sln = Solution()

strs = ["flower","fly","flex"]
res = sln.longestCommonPrefix(strs)
print(res)

strs = ["flower"]
res = sln.longestCommonPrefix(strs)
print(res)

strs = ["abc","abcdefg"," "]
res = sln.longestCommonPrefix(strs)
print(res)

strs = [ ]
res = sln.longestCommonPrefix(strs)
print(res)


strs = ["",""]
res = sln.longestCommonPrefix(strs)
print(res)
