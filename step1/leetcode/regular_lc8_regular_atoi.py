import re
class Solution(object):
    def myAtoi(self,s):
        ans = re.findall("^[\+\-]?\d+",s.lstrip())
        ans = 0 if ans== [] else int(''.join(ans))
        ans = max(min(ans,2**31-1),-2**31)
        return ans

sln = Solution()
res = sln.myAtoi("   321 hello")
print(res)
res = sln.myAtoi("   -42")
print(res)
res = sln.myAtoi(" 4193 with words")
print(res)
res = sln.myAtoi("-91283472332")
print(res)
res = sln.myAtoi("words and 999")
print(res)
        
