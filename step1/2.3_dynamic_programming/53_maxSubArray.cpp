#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int f = 0;
        int result = INT_MIN;
        for(int i = 0; i< nums.size(); i++)
        {
            int A,B;
            f = max(f + nums[i], nums[i]);
            result = max(result,f);
        }
        return result;
    }
};

int main(){
    Solution* sln = new Solution();
    vector<int> nums({-2,1,-3,4,-1,2,1,-5,4});
    int res;
    res = sln->maxSubArray(nums);
    cout<<res<<endl;
    return 0;
}
