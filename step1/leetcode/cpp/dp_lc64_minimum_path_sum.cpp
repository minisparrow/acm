/*
leetcode 64 
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //dp[0][j] = dp[0][j-1]+grid[0][j]
        //dp[i][0] = dp[i-1][0]+grid[i][0]
        //dp[i][j] = max(dp[i-1][j] + grid[i][j], dp[i][j-1]+grid[i][j])
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size()));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                } else if (i == 0) {
                    dp[0][j] = dp[0][j-1] + grid[0][j];
                } else if (j == 0) {
                    dp[i][0] = dp[i-1][0] + grid[i][0]; 
                } else {
                    int a = dp[i-1][j] + grid[i][j];
                    int b = dp[i][j-1] + grid[i][j];
                    dp[i][j] = min(a,b);
                }
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};

int main()
{
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> grid(rows,vector<int>(cols));
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> grid[i][j];
        }
    }
    Solution* sln = new Solution();
    int min_sum;
    min_sum = sln->minPathSum(grid);
    cout << min_sum << endl;
    return 0;
}