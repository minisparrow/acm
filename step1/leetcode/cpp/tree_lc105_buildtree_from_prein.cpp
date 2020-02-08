#include "treenode.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    inline const int iterator_to_int(vector<int> &v, vector<int>::iterator iter){
        return iter - v.begin();
    };

    void preorderTraversal(TreeNode *node){
        if (node){
            cout << node->val << endl;
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    TreeNode* buildTree( vector<int> &preorder, vector<int>& inorder) {
        if (preorder.size() == 0){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        vector<int>::iterator p = find(inorder.begin(), inorder.end(),root->val);

        int mid = iterator_to_int(inorder,p);

        // c++ similar to python array list 
        // python a[1:mid]
        // c++ :   a(b.begin()+1, b.begin()+mid+1) b相应的索引的值给到a.
        vector<int> left_preorder(preorder.begin()+1,preorder.begin()+mid+1); // preorder[1:mid+1]
        vector<int> left_inorder(inorder.begin(),inorder.begin()+mid);        //inorder[0:mid]
        vector<int> right_preorder(preorder.begin()+mid+1,preorder.end());    // preorder[mid+1:end]
        vector<int> right_inorder(inorder.begin()+mid+1,inorder.end());     // inorder[mid+1:end]

        root->left = buildTree(left_preorder,left_inorder);
        root->right = buildTree(right_preorder,right_inorder);
        return root;
    }

};

int main(){
     vector<int> preorder = {3,9,20,15,7};
     vector<int> inorder = {9,3,15,20,7};
     Solution* sln = new Solution();
     TreeNode* node = sln->buildTree(preorder,inorder);
     sln->preorderTraversal(node);
     return 0;
};