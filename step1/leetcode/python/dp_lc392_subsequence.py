class Solution(object):
   def isSubsequence(self, s, t):
       """
       :type s: str
       :type t: str
       :rtype: bool
       """
       # idea:
       # s[0:m] 是否为t[0:n]的子序列
       # 可以归结为: s[0:m-1]是否为t[0:n]的子序列
       i = 0
       while i < len(s):
           if s[i] in t:
               tindex = t.index(s[i])
               t = t[tindex+1:]
               i += 1
           else:
               return False
       return True


