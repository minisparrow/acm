#include <iostream>
#include <vector>
#include "treenode.hpp"

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if (root == NULL){
            return levels;
        }

        func(root,0);

        vector<vector<int>> new_vector = {};
        for(int i=levels.size()-1; i >= 0; i--){
            new_vector.push_back({});
            for( int j=0; j< levels[i].size(); j++){
               int idx = levels.size() - i - 1;
               new_vector[idx].push_back(levels[i][j]);
            }
        }
        return new_vector;
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
    ans = sln->levelOrderBottom(p);
    TraversalVectorOfVector(ans);
    return 0;

}

