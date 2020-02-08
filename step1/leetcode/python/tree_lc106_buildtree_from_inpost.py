# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    # recursive, first find root in preorder, 
    # find the index of root in inorder list.
    # than split the tree into left and right. 
    def buildTree(self,inorder,postorder):
        # preorder: List(int)
        # inorder : List(int)

        
        if len(postorder) == 0:
            return None

        root = TreeNode(postorder[-1])

        mid = inorder.index(postorder[-1])

        root.left = self.buildTree(inorder[:mid],postorder[0:mid])
        root.right = self.buildTree(inorder[mid+1:],postorder[mid:-1])

        return root

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]

sln = Solution()
root = sln.buildTree(inorder,postorder)

def preorderTraverse(p):
    if p:
       print(p.val)
       preorderTraverse(p.left)
       preorderTraverse(p.right)

preorderTraverse(root)