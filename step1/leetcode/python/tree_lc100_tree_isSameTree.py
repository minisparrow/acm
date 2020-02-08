# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
    
def PreorderTraversal(p,elem_list):
    """
    :type p: TreeNode
    """
    if p :
        print(p.val)
        PreorderTraversal(p.left,elem_list)
        PreorderTraversal(p.right,elem_list)

class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """

        if p == None and q == None:
            return True
        elif p == None or q == None: 
            return False
        elif p.val != q.val:
            return False
        else:
            return  self.isSameTree(p.left,q.left) and self.isSameTree(p.right,q.right)


if __name__ == "__main__":
    sln = Solution()

    p = TreeNode(1)
    p.left = TreeNode(2)

    q = TreeNode(1)
    q.left = TreeNode(None)
    q.right = TreeNode(2)

    ans = sln.isSameTree(p,q)
    print(ans)

        
        