#include "treenode.hpp"
#include <iostream>
#include <vector>

class Solution {
public:
    vector<int> ans = {};
    vector<int> inorderTraversal(TreeNode* root) {
        if(root){
            inorderTraversal(root->left);
            ans.push_back(root->val);
            inorderTraversal(root->right);
        }
        return ans;
    }
};

int main()
{
    TreeNode* p = new TreeNode(3);
    p->left = new TreeNode(9);
    p->right = new TreeNode(20);
    p->right->left = new TreeNode(15);
    p->right->right = new TreeNode(7);

    Solution* sln = new Solution();
    vector<int> ans;
    ans = sln->inorderTraversal(p);
    TraversalVector(ans);
    return 0;

}