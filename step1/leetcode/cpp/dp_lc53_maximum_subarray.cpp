#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxSubArray2(vector<int>& nums) {
        int result = INT_MIN;
        vector<int> f(nums.size());
        int A,B;
        for(int i = 0; i< nums.size(); i++)
        {
            if (i == 0){
                f[i] = nums[i];
            }
            A = f[i-1] + nums[i];
            B = nums[i];
            f[i] = max(A,B);
        }
        return *max_element(f.begin(),f.end());
    }

    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        int f = 0;
        for(int i = 0; i< nums.size(); i++)
        {
            f = max(f + nums[i],nums[i]);
            result = max(f,result);
        }
        return result;
    }
};

void test_maxArray(){
    vector<int> input_array = {-2,1,-3,4,-1,2,1,-5,4};
    Solution* sln = new Solution();
    int result = sln->maxSubArray(input_array);
    cout << result << endl;
}


int main(){
    test_maxArray();
    return 0;
}

