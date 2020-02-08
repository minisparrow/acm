#include "treenode.hpp"
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> levels = {};

    void func(TreeNode* node, int level)
    {
        if (levels.size() == level){
            levels.push_back({});
        }
        levels[level].push_back(node->val);
        
        if (node->left){
            func(node->left, level + 1);
        }
        if (node->right){
            func(node->right, level + 1);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if (root == NULL){
            return levels;
        }

        func(root,0);
        return levels;
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
    vector<vector<int>> ans;
    ans = sln->levelOrder(p);
    TraversalVectorOfVector(ans);
    return 0;

}