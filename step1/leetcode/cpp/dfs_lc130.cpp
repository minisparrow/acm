/*
作者：ZZYuting
链接：https://leetcode-cn.com/problems/surrounded-regions/solution/cbeats-9465easy-to-understand-by-zzyuting/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

/*
First, check the four border of the matrix. If there is a element is
'O', alter it and all its nei***or 'O' elements to '1'.

Then ,alter all the 'O' to 'X'

At last,alter all the '1' to 'O'

For example:

         X X X X           X X X X             X X X X
         X X O X  ->       X X O X    ->       X X X X
         X O X X           X 1 X X             X O X X
         X O X X           X 1 X X             X O X X
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()==0){
            return;
        }
        int rows=board.size(),cols=board[0].size();

        //第０列或者最后一列的有０的地方都标记为１
        for(int i=0;i<rows;i++){
            dfs(board,i,0);
            dfs(board,i,cols-1);
        }

        //第０行或者最后一行有０的地方都标记为１
        for(int j=1;j<cols-1;j++){
            dfs(board,0,j);
            dfs(board,rows-1,j);
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='1'){
                    board[i][j]='O';
                }
                else{
                    board[i][j]='X';
                }
            }
        }
    }
private:
    void dfs(vector<vector<char>>& board,int i,int j){
        if(i>=0&&i<board.size()&&j>=0&&j<board[0].size()&&board[i][j]=='O'){
            board[i][j]='1';
            dfs(board,i-1,j);
            dfs(board,i+1,j);
            dfs(board,i,j-1);
            dfs(board,i,j+1);
        }
    }
};

int main()
{
    Solution *sln = new Solution();
    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','X','O','X'},
        {'X','O','X','X'},
        {'X','O','X','X'}};

    cout <<"before..." << endl;
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            cout << board[i][j] << " " ;
        }
        cout << endl;
    }
    sln->solve(board);

    cout <<"after ..." << endl;
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            cout << board[i][j] << " " ;
        }
        cout << endl;
    }
    return 0;
}