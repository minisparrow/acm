#include <vector>
#include <iostream>
using namespace std;
// Definition for a binary tree node.
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