# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        fast, slow = head, head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if fast == slow: 
                return True
        return False

def create_linklist(list_elems):
    node = ListNode(0)
    node_ret = node
    for i in list_elems: 
        tmp = ListNode(i)
        node.next = tmp
        node = node.next
    return node_ret.next

def create_cycle_linklist(list_elems,pos):
    node = ListNode(0)
    node_ret = node

    for i in list_elems: 
        tmp = ListNode(i)
        node.next = tmp
        node = node.next

    start = node_ret.next 
    if pos != -1:
       for i in range(0,len(list_elems)):
           node_ret = node_ret.next
           if i == pos:
               break
       node.next = node_ret
    return start

def transverse(node):
    node_list = []
    while node != None:
        node_list.append(node.val)
        node = node.next
    print(node_list)
if __name__ == "__main__":
    list1 = [3,2,0,-4]
    pos = -1

    node = create_cycle_linklist(list1,pos)
    # transverse(node)
    sln = Solution()
    ans = sln.hasCycle(node)
    print(ans)
