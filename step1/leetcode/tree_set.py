# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    # lc94
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ans = []
        if root == None:
            return None
        def helper(node):
            if node.left:
                helper(node.left)
            ans.append(node.val)
            if node.right:
                helper(node.right)

        helper(root)
        return ans
            
    # lc144
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ans = []
        if root == None:
            return None
        def helper(node):
            ans.append(node.val)
            if node.left:
                helper(node.left)
            if node.right:
                helper(node.right)

        helper(root)
        return ans
    
    # lc145 
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ans = []
        if root == None:
            return None
        def helper(node):
            if node.left:
                helper(node.left)
            if node.right:
                helper(node.right)
            ans.append(node.val)

        helper(root)
        return ans

    #lc102
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        levels = []
        if root == None:
            return levels
        
        def helper(node,level):
            if len(levels) == level:
                levels.append([])
            levels[level].append(node.val)
            
            if node.left:
                helper(node.left, level + 1)
            
            if node.right:
                helper(node.right, level + 1)
                
        helper(root,0)
        return levels

    # lc107
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        levels = []
        if root == None:
            return levels
        def helper(node,level):
            if len(levels) == level:
                levels.append([])
            levels[level].append(node.val)
            if node.left:
                helper(node.left, level + 1)
            if node.right:
                helper(node.right, level + 1)
        helper(root,0)
        levels.reverse()
        return levels

    # lc105 
    def buildTree_from_preorder_inorder(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        # recursive 
        # 1. find root
        # 2. find mid index 
        # 3. split tree to left tree , and right tree
        # 4. recursive the left tree and right tree 
        if len(preorder) == 0:
            return None
        
        root = TreeNode(preorder[0])
        mid = inorder.index(preorder[0])
        
        root.left = self.buildTree_from_preorder_inorder(preorder[1:mid+1],inorder[:mid])
        root.right = self.buildTree_from_preorder_inorder(preorder[mid+1:],inorder[mid+1:])
        
        return root

    #lc106
    def buildTree_from_postorder_inorder(self,inorder,postorder):
        # preorder: List(int)
        # inorder : List(int)
        if len(postorder) == 0:
            return None

        root = TreeNode(postorder[-1])

        mid = inorder.index(postorder[-1])

        root.left = self.buildTree_from_postorder_inorder(inorder[:mid],postorder[0:mid])
        root.right = self.buildTree_from_postorder_inorder(inorder[mid+1:],postorder[mid:-1])

        return root


    def PrintpreorderTraverse(self,p,ans):
        if p:
           ans.append(p.val)
           self.PrintpreorderTraverse(p.left,ans)
           self.PrintpreorderTraverse(p.right,ans)

    #lc100
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

    #lc101
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def isMirror(root1,root2):
            if root1 == None and root2 == None:
                return True
            elif root1 == None or root2 == None:
                return False 
            elif root1.val != root2.val: 
                return False
            else:
                return isMirror(root1.left,root2.right) and isMirror(root1.right,root2.left)

        return isMirror(root,root)


#test 
def test_buildtree_from_preorder_inorder():
    preorder = [3,9,20,15,7]
    inorder = [9,3,15,20,7]
    sln = Solution()
    root = sln.buildTree_from_preorder_inorder(preorder,inorder)
    ans = []
    sln.PrintpreorderTraverse(root,ans)
    print(ans)

def test_buildtree_from_postorder_inorder():
    inorder = [9,3,15,20,7]
    postorder = [9,15,7,20,3]
    sln = Solution()
    root = sln.buildTree_from_postorder_inorder(inorder,postorder)
    ans = []
    sln.PrintpreorderTraverse(root,ans)
    print(ans)



if __name__ == "__main__":
    test_buildtree_from_preorder_inorder()
    print("---")
    test_buildtree_from_postorder_inorder()
            