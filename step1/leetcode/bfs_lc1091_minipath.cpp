#include <queue>
#include <vector>
#include <iostream>
#include <memory>  //shared_ptr, make_shared
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        bx = grid.size();
        by = grid[0].size();
        queue<shared_ptr<Node>> que;
        if(grid[0][0] || grid[bx-1][by-1]) return -1;
        que.push(make_shared<Node>(0,0,1));
        while(que.size()){
            auto now = que.front();
            que.pop();
            if(now->x == bx-1 && now->y == by-1) return now->step;
            for(int i = 0;i < 8; ++i){
                int nx = now->x + dir[i][0];
                int ny = now->y + dir[i][1];
                if(nx < 0 || nx >= bx || ny < 0 || ny >= by || grid[nx][ny])
                    continue;
                que.push(make_shared<Node>(nx, ny, now->step+1));
                grid[nx][ny] = 1;
            }
        }
        return -1;
    }
private:
    struct Node{
        int x, y;
        int step;
        Node(int _x, int _y, int _s):x(_x),y(_y),step(_s){}
    };
    int bx, by;
    int dir[8][2] = {
        {0,1},  //右
        {1,1},  //右下角
        {1,0},  //下
        {1,-1}, //右上角
        {-1,0}, //左
        {-1,-1},//左上角
        {0,-1}, //上
        {-1,1}  //左下角
    };
};

void test(vector<vector<int>>& A){
    Solution *sln = new Solution();
    int res;
    res = sln->shortestPathBinaryMatrix(A);
    cout << res << endl;
}

int main()
{
    vector<vector<int> > A(3,vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }
    test(A);
    return 0;
     
}