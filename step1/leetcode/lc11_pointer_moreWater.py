# -*- coding: utf-8 -*-
class Solution(object):

   def maxArea_basic(self, height): # O(n^2)
      #:type height: List[int]
      #:rtype: int
      length = len(height)
      maxarea = 0;
      for i in range(0,length):
         for j in range(i+1,length):
             area = (j-i)*(min(height[i],height[j])) 
             if area > maxarea: 
                 maxarea = area
      return maxarea

   def maxArea_twopointer(self, height): # O(n)
      #:type height: List[int]
      #:rtype: int
      length = len(height)
      i,j,area = 0, length-1,0

      while i < j:
          if (height[i] < height[j]):
              area = max(area, height[i]*(j-i))
              i += 1
          else:
              area = max(area, height[j]*(j-i))
              j -= 1
      return area 

height = [1,8,6,2,5,4,8,3,7]
sln = Solution()
res = sln.maxArea_basic(height)
print(res)
res = sln.maxArea_twopointer(height)
print(res)





    
