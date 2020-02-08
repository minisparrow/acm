# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # 1. linklist to array list 
        node_list = []
        while head != None:
            node_list.append(head.val)
            head = head.next
        reverse_list = node_list[::-1]

        # 2. array list to linklist
        new_link = ListNode(0)
        ret = new_link
        for i in reverse_list:
            tmp = ListNode(i)

            new_link.next = tmp
            new_link = new_link.next
        return ret.next

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

def test(list_elems):
    node1 = create_linklist(list_elems)
    print("linklist: ")
    transverse(node1)
    sln = Solution()
    ans = sln.reverseList(node1)
    print("after reverse:")
    transverse(ans)

if __name__ == "__main__":
    test([1,2,3,4])
    test([5,6,7,8])
    test([2])
