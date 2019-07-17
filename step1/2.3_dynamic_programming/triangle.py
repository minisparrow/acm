import numpy as np 


class Solution(object):
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





