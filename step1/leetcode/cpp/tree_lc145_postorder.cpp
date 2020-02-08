#include "treenode.hpp"
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> ans = {};
    void func(TreeNode* node)
    {
        if (node->left){
            func(node->left);
        }
        if (node->right){
            func(node->right);
        }
        ans.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL){
            return {};
        }
        func(root);
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
    ans = sln->postorderTraversal(p);
    TraversalVector(ans);
    return 0;

}

