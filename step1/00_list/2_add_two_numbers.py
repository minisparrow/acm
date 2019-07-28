# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x=None,next = None):
        self.val = x
        self.next = next

class List(object):
    def __init__(self, x = None):
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

        def sum_linknode(l):
           curnode = l.root
           i = 0 
           sum_l = 0

           while curnode is not l.tailnode.next:
               sum_l += curnode.val * 10**i
               curnode = curnode.next
               i += 1
           return sum_l

        sum_l1 = sum_linknode(l1)
        sum_l2 = sum_linknode(l2)

        sum = sum_l1 + sum_l2 

        print(sum)

        l = List(sum%10)
        sum = sum/10
        while sum != 0:
            l.append(sum%10)
            sum = sum/10

        l.iter_node()

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

    sln = Solution()
    sln.addTwoNumbers(l1,l2)

