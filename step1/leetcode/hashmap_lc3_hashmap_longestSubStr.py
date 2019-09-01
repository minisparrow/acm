#-*- coding: utf-8 *-*
# leetcode3: https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
# Given a string, find the length of the longest substring without repeating characters.
# 
# Example 1:
# 
#     Input: "abcabcbb"
#     Output: 3 
#     Explanation: The answer is "abc", with the length of 3. 

class Solution(object):
   def lengthOfLongestSubstring(self, s):
   # :type s: str
   # :rtype: int
      length = len(s)
      table = {}
      start = 0
      globalLongest = 0
      # 一个用于计算当前最长的字符串长度; start, end , globalLongest = end - start + 1
      # 一个用于改变start, end的索引直
      # start, end更新的规则:
      #   如果当前字符在字典中没有，end 就是当前的索引
      #   如果当前字符在字典中已经有了，更新start直，start 直更新为字典中以这个直为key的value(就是下一个索引),end 就是当前的索引
      for idx, s_char in enumerate(s):
          if s_char in table:
              start = max(table[s_char],start) 
              end = idx
              table[s_char] = idx + 1
          table[s_char] = idx + 1
          end = idx
          subLength = end - start + 1
          globalLongest = max(subLength,globalLongest)
      print(globalLongest)
      return globalLongest


if __name__ == "__main__":
    sln = Solution()
    sln.lengthOfLongestSubstring("abcabcbb")
    sln.lengthOfLongestSubstring("abcdbcbb")
    sln.lengthOfLongestSubstring("abcdabcdef")
