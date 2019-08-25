#include "treenode.hpp"
#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL){
            return true;
        }
        else if(p == NULL || q == NULL){
            return false;
        }
        else if(p->val != q->val){
            return false;
        }
        else{
            return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }
    }
};

int main()
{
    TreeNode* p = new TreeNode(3);
    p->left = new TreeNode(9);
    p->right = new TreeNode(20);

    TreeNode* q = new TreeNode(3);
    q->left = new TreeNode(9);
    q->right = new TreeNode(20);

    Solution* sln = new Solution();
    bool ans = sln->isSameTree(p,q);
    cout<<ans<<endl;
    return 0;

}