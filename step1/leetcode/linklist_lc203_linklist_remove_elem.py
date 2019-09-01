# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        pre = ListNode(0)
        pre.next = head 
        curr = head
        tmp = pre
        while curr != None: 
            # operation 
            if curr.val == val: 
                #delete head 
                pre.next = curr.next
            else:
                pre = curr 
            curr = curr.next
        return tmp.next
        
def transverse(node):
    node_list = []
    while node != None:
        node_list.append(node.val)
        node = node.next
    print(node_list)
    
def create_linklist(list_elems):
    node = ListNode(0)
    node_ret = node
    for i in list_elems: 
        tmp = ListNode(i)
        node.next = tmp
        node = node.next
    return node_ret.next

def test(list_elems, val):
    node1 = create_linklist(list_elems)
    print("linklist: ")
    transverse(node1)
    sln = Solution()
    ans = sln.removeElements(node1,val)
    print("after remove:", val)
    transverse(ans)

if __name__ == "__main__":
    test([1,2,3,4], 4)
    test([2,2,3,3,4],2)
    test([2,2],2)
