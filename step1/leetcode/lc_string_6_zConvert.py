class Solution(object):
   def convert(self, s, numRows):
      """
      :type s: str
      :type numRows: int
      :rtype: str
      """

      if numRows == 1:
         return s
      else:
         rowVec = [[] for i in range(0,numRows)]
         godown = True
         idx_in_s = 0
         row = 0
         ans = []
         while idx_in_s != len(s):
             rowVec[row].append(s[idx_in_s])

             if godown: 
                 row += 1
             else:
                 row -= 1
             if row == 0 or row == numRows-1:
                 godown = not godown

             idx_in_s += 1

         for i in range(0,numRows):
             ans += rowVec[i]

         return ''.join(ans)


sln = Solution()
s = "leetcode"
res = sln.convert(s,3)
print(res)
