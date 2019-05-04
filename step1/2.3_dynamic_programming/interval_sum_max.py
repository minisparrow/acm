#coding:utf-8
# 一堆数字中，任选几个不能相邻的数字，使得求和最大。
arr = [1,2,4,1,7,8,3]

def rec_opt(arr,i):
    if i == 0:
        return arr[0]
    elif i == 1:
        return max(arr[0],arr[1])
    else:
        A = rec_opt(arr,i-2) + arr[i]
        B = rec_opt(arr,i-1) 
        return max(A,B)

print(rec_opt(arr,len(arr)-1))
