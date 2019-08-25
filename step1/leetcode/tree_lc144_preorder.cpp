#include <iostream>
#include <vector>
using namespace std;

// * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> ans = {};
    void func(TreeNode* node)
    {
        ans.push_back(node->val);
        if (node->left){
            func(node->left);
        }
        if (node->right){
            func(node->right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL){
            return {};
        }
        func(root);
        return ans;
    }
};

int main()
{
    TreeNode* p = new TreeNode(1);
    p->right = new TreeNode(2);
    p->right->left = new TreeNode(3);

    Solution* sln = new Solution();
    vector<int> ans;
    ans = sln->preorderTraversal(p);
    for(int i = 0; i< ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    return 0;

}