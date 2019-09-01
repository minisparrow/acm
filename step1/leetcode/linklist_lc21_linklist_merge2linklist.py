# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """

        l3 = ListNode(0)
        ans = l3
        while l1 != None or l2 != None:
           if l1 != None and l2 != None:
               if l1.val < l2.val:
                   node = ListNode(l1.val)
                   l1 = l1.next
               else:
                   node = ListNode(l2.val)
                   l2 = l2.next
               l3.next = node
               l3 = l3.next
           else:
               if l1 != None:
                   l3.next = l1 
                   l1 = l1.next
               elif l2 != None:
                   l3.next = l2 
                   l2 = l2.next
               l3 = l3.next
        ans = ans.next
        return ans
        
def create_linklist(list_elems):
    node = ListNode(0)
    node_ret = node
    for i in list_elems: 
        tmp = ListNode(i)
        node.next = tmp
        node = node.next
    return node_ret.next

if __name__ == "__main__":
    list1 = [1,2,3]
    list2 = [4,5,6]
    
    linklist1 = create_linklist(list1)
    linklist2 = create_linklist(list2)
    
    sln = Solution()
    ans = sln.mergeTwoLists(linklist1,linklist2)
    
    while ans != None:
        print(ans.val)
        ans = ans.next
