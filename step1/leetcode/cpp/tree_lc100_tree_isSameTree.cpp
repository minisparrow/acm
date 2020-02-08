#include <iostream>
#include <string>
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

int main(){
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(NULL);
    p->right = new TreeNode(2);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(NULL);
    q->right = new TreeNode(2);

    Solution* sln = new Solution();
    bool ans = sln->isSameTree(p,q);
    cout << ans << endl;
    return 0;
}