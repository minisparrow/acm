# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):

    # recursive 
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return self.isMirror(root,root)

    def isMirror(self,root1,root2):
        if root1 == None and root2 == None:
            return True
        elif root1 == None or root2 == None:
            return False 
        elif root1.val != root2.val: 
            return False
        else:
            return self.isMirror(root1.left,root2.right) and self.isMirror(root1.right,root2.left)

if __name__ == "__main__":
    sln = Solution()
    tree = TreeNode(1)
    tree.left = TreeNode(2)
    tree.right = TreeNode(2)
    tree.left.left = TreeNode(3)
    tree.left.right = TreeNode(4)
    tree.right.left = TreeNode(4)
    tree.right.right = TreeNode(3)
    ans = sln.isSymmetric(tree)
    print(ans)
