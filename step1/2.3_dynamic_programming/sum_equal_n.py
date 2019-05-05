#coding:utf-8
# 从一堆数字中选择几个，使得能够拼出和为SUM的数
# 转换成一个子集问题
import numpy as np

arr = [3,34,4,12,5,2]
arr = [3,34,4,12,5,2,10,11,12,13,15,18,39]
Sum = 9

#--------------------------------------------------------
# recursive subset
#--------------------------------------------------------
def rec_subset(arr,i,residual_sum):
    if residual_sum == 0:
        return True
    elif i == 0:
        return arr[i] == residual_sum
    elif residual_sum < arr[i]:
        return rec_subset(arr,i-1,residual_sum)
    else:
        A = rec_subset(arr,i-1,residual_sum)
        B = rec_subset(arr,i-1,residual_sum - arr[i]) 
        return A or B


print(rec_subset(arr,len(arr)-1,9))
print(rec_subset(arr,len(arr)-1,10))
print(rec_subset(arr,len(arr)-1,11))
print(rec_subset(arr,len(arr)-1,12))
print(rec_subset(arr,len(arr)-1,13))

#--------------------------------------------------------
# dynamic programming subset
#--------------------------------------------------------
#     s   0   1  2  3  4  5  6  7  8  9 
# arr  
# 0       T   F  F  T  F  F  F  F  F  F 
# 1       T
# 2       T
# 3       T
# 4       T
# 5       T
# 
def dp_subset(arr,residual_sum):
   subset = np.zeros((len(arr),residual_sum+1),dtype=bool)
   subset[:,0] = True
   subset[0,:] = False 
   subset[0,arr[0]] = True
   for i in range(1,len(arr)):
      for s in range(1,residual_sum+1): 
         if arr[i] > s:
             subset[i,s] = subset[i-1,s] 
         else:
             A = subset[i-1,s - arr[i]]  # 选择第i个元素
             B = subset[i-1,s]           # 不选择第i个元素
             subset[i,s] = A or B 
   rol,col = subset.shape
   return  subset[rol-1,col-1]
   
print(dp_subset(arr,9 ))
print(dp_subset(arr,10))
print(dp_subset(arr,11))
print(dp_subset(arr,12))
print(dp_subset(arr,13))

import time
t1 = time.time()
for i in range(1000):
   (dp_subset(arr,9 ))
t1 = time.time() - t1
print("t1 : %f" %t1)

t2 = time.time()
for i in range(1000):
   (rec_subset(arr,len(arr)-1,9 ))
t2 = time.time() - t2
print("t2 : %f" %t2)
