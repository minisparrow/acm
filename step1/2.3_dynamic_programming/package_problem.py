#coding:utf-8
# n = 4
# w = 2, 1, 3, 2
# v = 3, 2, 4, 2
# W = 5
# 选择总重量为W，value v 总和最高的方案

n = 4
w = [2, 1, 3, 2]
v = [3, 2, 4, 2]
W = 5

def rec_package(i,s):
    if i == n:
        res = 0
    elif s < w[i]: # s : 剩余重量
        res = rec_package(i+1,s)
    else:
        A = rec_package(i+1,s)  #不选i
        B = rec_package(i+1,s-w[i]) + v[i] #选i
        res = max(A,B)
    return res


res = rec_package(0,W)
print(res)
