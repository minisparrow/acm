# -*- coding: utf-8 -*-
class Solution(object):
    def isPalindrome(self,x):
        #x : int 
        #return :int 

        i = 0 
        y = x
        sign = -1 if x < 0 else 1
        if sign == -1:
            return False
        ans = 0
        while x != 0:
            # 先求最低位, 通过右移的方式依次求出最低位的直
            bit = (x % 10) 
            i += 1
            x = x/10

            # 每次求出的最低位，在下个最低位过来时，左移原先求出的最低位(*10), 加上最新的低位直
            ans *= 10   
            ans += bit 
        print(ans)
        return ans == y


sln = Solution()
ans = sln.isPalindrome(-123)
print(ans)
ans = sln.isPalindrome(1221)
print(ans)
ans = sln.isPalindrome(121)
print(ans)
ans = sln.isPalindrome(120)
print(ans)
