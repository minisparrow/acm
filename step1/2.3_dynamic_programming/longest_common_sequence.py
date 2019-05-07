#coding:utf-8
# 最长公共子序列

import numpy as np

n = 6
m = 6

s = "abcdec"
t = "becdce"

dp = np.zeros((n+1,m+1))

for i in range(0,n):
   for j in range(0,m):
      if s[i] == t[j]:
          dp[i+1,j+1]  = dp[i,j] + 1
      else:
          dp[i+1,j+1]  = max(dp[i,j+1],dp[i+1,j])


print(dp[n,m])
