#coding:utf-8
# 一堆数字中，任选几个不能相邻的数字，使得求和最大。
import time 
import numpy as np

arr = [1,2,4,1,7,8,3]

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
print("time:", t1)


#---------------------------------------------------------
# dynamic programming 
#---------------------------------------------------------
def dp_opt(arr,i):
    dp = np.zeros(len(arr))
    if i == 0:
        return arr[0]
    elif i == 1:
        return max(arr[0],arr[1])
    else:
        A = dp_opt(arr,i-2) + arr[i]
        B = dp_opt(arr,i-1) 
        dp[i] = max(A,B)
        return dp[i]



t2 = time.time()
for i in range(1000):
   (dp_opt(arr,len(arr)-1))
t2 = time.time() - t2
print("time:", t2)

#---------------------------------------------------------
# time compare
#---------------------------------------------------------
print("dp faster that recursive %f times" % (t1/t2 ))
