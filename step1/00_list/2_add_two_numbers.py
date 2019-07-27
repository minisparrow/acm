# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x=None,next = None):
        self.val = x
        self.next = next

class List(object):
    def __init__(self, x):
        self.root = ListNode(x)
        self.tailnode = None
        self.length = 0 

    def append(self,x):
        node = ListNode(x)
        tailnode = self.tailnode 
        if tailnode is None:
            self.root.next = node
        else:
            tailnode.next = node
        self.tailnode = node
        self.length += 1

    def iter_node(self):
        curnode = self.root
        while curnode is not None:
            print(curnode.val)
            curnode = curnode.next


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """

def test(l1,l2):
    sln = Solution()
    sln.addTwoNumbers(l1,l2)


if __name__ == "__main__":
    l1 = List(1)
    l1.append(2)
    l1.append(3)

    l2 = List(4)
    l2.append(5)
    l2.append(6)

    l1.iter_node()
    l2.iter_node()




