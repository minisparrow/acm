/*
作者：LeetCode
链接：https://leetcode-cn.com/problems/number-of-islands/solution/dao-yu-shu-liang-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//并查集
class UnionFind {
public:
  UnionFind(vector<vector<char>>& grid) {
    count = 0;
    int m = grid.size();
    int n = grid[0].size();
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] == '1') {
            parent.push_back(i * n + j);
            ++count;
          }
          else parent.push_back(-1);
          rank.push_back(0);
        }
    }
  }

  int find(int i) { // path compression
    if (parent[i] != i) parent[i] = find(parent[i]);
    return parent[i];
  }

  void Union(int x, int y) { // union with rank
    int rootx = find(x);
    int rooty = find(y);
    if (rootx != rooty) {
      if (rank[rootx] > rank[rooty]) parent[rooty] = rootx;
      else if (rank[rootx] < rank[rooty]) parent[rootx] = rooty;
      else {
        parent[rooty] = rootx; rank[rootx] += 1;
      }
      --count;
    }
  }

  int getCount() const {
    return count;
  }

private:
  vector<int> parent;
  vector<int> rank;
  int count; // # of connected components
};

class Solution {
public:
  vector<vector<char>> grid;
  int numIslands(vector<vector<char>>& grid) {
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();

    UnionFind uf (grid);
    int num_islands = 0;
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == '1') {
          grid[r][c] = '0';
          if (r - 1 >= 0 && grid[r-1][c] == '1') uf.Union(r * nc + c, (r-1) * nc + c);
          if (r + 1 < nr && grid[r+1][c] == '1') uf.Union(r * nc + c, (r+1) * nc + c);
          if (c - 1 >= 0 && grid[r][c-1] == '1') uf.Union(r * nc + c, r * nc + c - 1);
          if (c + 1 < nc && grid[r][c+1] == '1') uf.Union(r * nc + c, r * nc + c + 1);
        }
      }
    }

    return uf.getCount();
  }

  vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
    vector<int> ans;
    //UnionFind uf (m * n);
    vector<vector<char>> grid(m, vector<char>(n,'0'));
    vector<vector<char>> grid2(m, vector<char>(n,'0'));

    for (auto& pos : positions) {
      int r = pos[0];
      int c = pos[1];
      grid[r][c] = '1';
      print(grid);
      grid2 = grid;
      int num = numIslands(grid2);
      ans.push_back(num);
    }

    return ans;
  }

  void print(vector<vector<char>> &grid){
      cout << "---" << endl;
      for (int i = 0; i < grid.size(); i++) {
         for (int j = 0; j < grid[0].size(); j++) {
             cout << grid[i][j] << " ";
         }
         cout << endl;
      }
  }
};

int main()
{
    Solution *sln = new Solution();
    int m = 3, n = 3;
    vector<vector<int>> positions = {{0,0},{0,1},{1,2},{2,1}};
    vector<int> num = sln->numIslands2(m,n,positions);
    for(int i = 0; i < num.size(); i++) {
        cout << num[i] << endl;
    }
    return 0;
}
