//#include "treenode.hpp"
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void TraversalVectorOfVector(vector< vector<int> > levels){
    for(int i=0; i< levels.size(); i++){
        cout<<"[";
        for( int j=0; j< levels[i].size(); j++){
            cout<<levels[i][j] <<",";
        }
        cout<<"]"<<endl;
    }
}

void TraversalVector(vector<int> levels){
    for(int i=0; i< levels.size(); i++){
        cout<<levels[i] << endl;
    }
}

class Solution {
public:
    vector<int> ans = {};
    vector<vector<int>> levels= {};

    // lc94
    void helper_inorder(TreeNode* node)
    {
        if (node->left){
            helper_inorder(node->left);
        }
        ans.push_back(node->val);
        if (node->right){
            helper_inorder(node->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL){
            return {};
        }
        helper_inorder(root);
        return ans;
    }

    //lc144
    void helper_preorder(TreeNode* node)
    {
        ans.push_back(node->val);
        if (node->left){
            helper_preorder(node->left);
        }
        if (node->right){
            helper_preorder(node->right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL){
            return {};
        }
        helper_preorder(root);
        return ans;
    }

    //lc145
    void helper_postorder(TreeNode* node)
    {
        if (node->left){
            helper_postorder(node->left);
        }
        if (node->right){
            helper_postorder(node->right);
        }
        ans.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL){
            return {};
        }
        helper_postorder(root);
        return ans;
    }

    //lc102
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

void test_inorderTraversal()
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
}

void test_preorderTraversal()
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

}

void test_postorderTraversal()
{
    TreeNode* p = new TreeNode(1);
    p->right = new TreeNode(2);
    p->right->left = new TreeNode(3);

    Solution* sln = new Solution();
    vector<int> ans;
    ans = sln->postorderTraversal(p);
    for(int i = 0; i< ans.size(); i++){
        cout<<ans[i]<<endl;
    }

}
int main(){
    test_inorderTraversal();
    cout << "---" <<endl;
    test_preorderTraversal();
    cout << "---" <<endl;
    test_postorderTraversal();
    return 0;
}