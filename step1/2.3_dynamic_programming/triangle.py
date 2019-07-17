# -*- coding: UTF-8 -*-
import numpy as np 

class Solution(object):
    # from top to bottom
    # f[i][j] 表示从最顶层元素开始，到第i行第j列的Sum.
    # 空间复杂度O(n^2), 时间复杂度O（n^2)
    def triangle_dp(self,arr,row):
       f = np.zeros((row,row))
       for i in range(0,row):
         for j in range(0,row):
             if j == 0: 
                 f[i][j] = f[i-1][j] + arr[i][j]
             elif i == j:
                 f[i][j] = f[i-1][j-1] + arr[i][j]
             else:
                 f[i][j] = min( f[i-1][j] + arr[i][j], f[i-1][j-1] + arr[i][j])
       return (min(f[row-1]))


    # from bottom to top 
    # arr[i][j] 表示从[i,j]位置的元素开始往下走一行的最小值。依次往上走，直到走到top最顶层的元素。
    # 空间复杂度O(1), 时间复杂度O（n^2)
    def triangle_dp_bottom2top(self,arr,row):
       for i in range(row-2,-1,-1):
         for j in range(0,i+1):
            arr[i][j] +=  min(arr[i+1][j],arr[i+1][j+1]) 
       return arr[0][0]

if __name__ == "__main__":

   row = 4
   arr = np.zeros((row,row))
   arr[0][0] = 2 
   arr[1][0] = 3
   arr[1][1] = 4
   arr[2][0] = 6
   arr[2][1] = 5
   arr[2][2] = 7
   arr[3][0] = 4
   arr[3][1] = 1
   arr[3][2] = 8
   arr[3][3] = 3

   sln = Solution()
   res = sln.triangle_dp(arr,row)
   print(res)

   res2 = sln.triangle_dp_bottom2top(arr,row)
   print(res2)




