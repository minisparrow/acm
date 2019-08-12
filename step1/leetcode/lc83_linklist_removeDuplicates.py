# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
    # """
    # :type head: ListNode
    # :rtype: ListNode
    # """ 
        if head == None:
            return head
        else:
            head_num = head.val 
            head_ret = head
            pre = head
            curr = head.next 
            while curr != None:
                   num = curr.val 
                   # if equal, delete
                   if num == head_num:
                       # delete head
                       pre.next = curr.next
                       curr = curr.next
                   else:
                       pre = curr 
                       head_num = num
                       curr = curr.next
            return head_ret
                
    
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

if __name__ == "__main__":
    list1 = [1,2,3,3,3,3,4,4,5,5]
    linklist1 = create_linklist(list1)

    # transverse(linklist1)
    
    sln = Solution()
    ans = sln.deleteDuplicates(linklist1)
    
    # while ans != None:
    #     print(ans.val)
    #     ans = ans.next

    transverse(ans)
