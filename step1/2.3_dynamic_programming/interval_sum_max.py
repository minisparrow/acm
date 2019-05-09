#coding:utf-8
# 一堆数字中，任选几个不能相邻的数字，使得求和最大。
import time 
import numpy as np

arr = [1,2,4,1,7,8,3]
arr = [4,1,1,9,1,2,3,4,6,2,9]

#---------------------------------------------------------
# recursive opt
#---------------------------------------------------------
def rec_opt(arr,i):
    if i == 0:
        return arr[0]
    elif i == 1:
        return max(arr[0],arr[1])
    else:
        A = rec_opt(arr,i-2) + arr[i]
        B = rec_opt(arr,i-1) 
        return max(A,B)

t1 = time.time()
for i in range(10000):
   (rec_opt(arr,len(arr)-1))
t1 = time.time() - t1
print("recursive time:", t1)
print(rec_opt(arr,len(arr)-1))


#---------------------------------------------------------
# dynamic programming 
#---------------------------------------------------------
def dp_opt(arr):
    dp = np.zeros(len(arr))
    dp[0] = arr[0]
    dp[1] = max(arr[0],arr[1])
    for i in range(2,len(arr)):
        A = dp[i-2] + arr[i]
        B = dp[i-1] 
        dp[i] = max(A,B)
    return dp[len(arr)-1]

t2 = time.time()
for i in range(1000):
   (dp_opt(arr))
t2 = time.time() - t2
print("dynamic time:", t2)
print(dp_opt(arr))

print("times",t1/t2)
