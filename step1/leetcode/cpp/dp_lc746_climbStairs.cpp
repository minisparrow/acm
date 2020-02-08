#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        //第i台阶的最小代价标记为: f[i]
        //f[i] = min(f[i-1],f[i-2]) + cost[i]
        //borders:
        //f[0] = cost[0]
        //f[1] = cost[1]
        int minCostClimbingStairs(vector<int>& cost){
            vector<int> f;
            cost.push_back(0);
            int min_value;

            for(int i = 0; i < cost.size(); i++){
                if ( i !=0 && i != 1) {
                    min_value = min(f[i-1],f[i-2]) + cost[i];
                    f.push_back(min_value);
                }
                else{
                    f.push_back(cost[i]);
                }
            }
            return f[cost.size()-1];
        }
};
/*
void test(){
    Solution *sln = new Solution();
//vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    vector<int> cost = {10,15,20};
    int ans;
    ans = sln->minCostClimbingStairs(cost);
    cout << ans << endl;
}
*/
