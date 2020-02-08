class TreeNode(object):
    def __init__(self,x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        def generate_trees(start, end):
            if start > end:
                return [None,]
            
            all_trees = []
            for i in range(start, end + 1):  # pick up a root
                # all possible left subtrees if i is choosen to be a root
                left_trees = generate_trees(start, i - 1)
                
                # all possible right subtrees if i is choosen to be a root
                right_trees = generate_trees(i + 1, end)
                
                # connect left and right subtrees to the root i
                for l in left_trees:
                    for r in right_trees:
                        current_tree = TreeNode(i)
                        current_tree.left = l
                        current_tree.right = r
                        all_trees.append(current_tree)
            
            return all_trees
        
        return generate_trees(1, n) if n else []


def preorder(root):
    preorder_list = []
    def helper(root):
        preorder_list.append(root.val)
        if root.left:
            helper(root.left)
        if root.right:
            helper(root.right)

    if root == None:
        return None
    helper(root)
    return preorder_list

def test():
    sln = Solution()
    all_trees = sln.generateTrees(3)
    for tree in all_trees:
        preorder_list = preorder(tree)
        print(preorder_list)

if __name__ == "__main__":
    test()