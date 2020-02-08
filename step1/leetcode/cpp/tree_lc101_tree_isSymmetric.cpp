#include <iostream>
using namespace std;
// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
       return isMirror(root,root);
    }

    bool isMirror(TreeNode* root1, TreeNode* root2){
        if (root1 == NULL && root2 == NULL) {
            return true;
        } else if (root1 == NULL or root2 == NULL) {
            return false;
        } else if (root1->val != root2->val){
            return false;
        } else
        {
            return isMirror(root1->left,root2->right) && isMirror(root1->right,root2->left);
        }
    }
};

int main(){
    Solution* sln = new Solution();
    TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(2);
    tree->left->left = new TreeNode(3);
    tree->left->right = new TreeNode(4);
    tree->right->left = new TreeNode(4);
    tree->right->right = new TreeNode(3);
    bool ans = sln->isSymmetric(tree);
    cout<<ans<<endl;
}