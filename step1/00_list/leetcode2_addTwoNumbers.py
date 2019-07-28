# -*- coding: utf-8 -*-
# leetcode 2:  https://leetcode-cn.com/problems/add-two-numbers/
# You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
# 
# You may assume the two numbers do not contain any leading zero, except the number 0 itself.
# 
# Example:
# 
#     Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
#     Output: 7 -> 0 -> 8
#     Explanation: 342 + 465 = 807.
# 
# Definition for singly-linked list.


class ListNode(object):
    def __init__(self, x=None):
        self.val = x
        self.next = None 

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        curr = ListNode(0)
        p = l1
        q = l2
        # curr = dummpyHead
        dummpyHead = curr
        carry = 0
        while p != None or q != None :
            # 当前直
            x = p.val if (p != None) else 0 
            y = q.val if (q != None) else 0 
            sum = x + y + carry
            curr.next = ListNode(sum%10)

            # 下一个直
            carry = sum / 10
            curr = curr.next
            p = p.next if (p != None) else p  
            q = q.next if (q != None) else q

        if carry > 0 : 
            curr.next = ListNode(carry)
        
        return dummpyHead.next

def test():
    l1 = ListNode(1)
    l1.next = ListNode(2)
    l1.next.next = ListNode(3)

    l2 = ListNode(4)
    l2.next = ListNode(5)
    l2.next.next = ListNode(6)

    sln = Solution()
    l_res = sln.addTwoNumbers(l1,l2)

    cur = l_res 
    while cur is not None: 
        print(cur.val)
        cur = cur.next

if __name__ == "__main__":
    test()
