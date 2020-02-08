class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        romanMap = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000 }

        ans = 0 
        for i in range(0,len(s)-1,1): 
            if romanMap[s[i]] < romanMap[s[i+1]]:
                ans -= romanMap[s[i]]
            else:
                ans += romanMap[s[i]]

        ans += romanMap[s[len(s)-1]]
        return ans


sln = Solution()

res = sln.romanToInt("IV")
print(res)

res = sln.romanToInt("IX")
print(res)

res = sln.romanToInt("LVIII")
print(res)
