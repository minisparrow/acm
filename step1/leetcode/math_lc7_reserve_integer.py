# -*- coding: utf-8 -*-
class Solution(object):
    def reverse(self,x):
        #x : int 
        #return :int 

        i = 0 
        sign = -1 if x < 0 else 1
        x = abs(x)
        ans = 0
        while x != 0:
            # 先求最低位, 通过右移的方式依次求出最低位的直
            bit = (x % 10) 
            i += 1
            x = x/10

            # 每次求出的最低位，在下个最低位过来时，左移原先求出的最低位(*10), 加上最新的低位直
            ans *= 10   
            ans += bit 
        ans = sign*ans

        if ans > 2**31-1 or ans < -2**31:
            return 0
        else:
            return ans

sln = Solution()
ans = sln.reverse(-123)
print(ans)
ans = sln.reverse(-12)
print(ans)
ans = sln.reverse(120)
print(ans)
