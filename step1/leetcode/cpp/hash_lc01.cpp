#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       map<int,int> a;
       vector<int> b(2,0);
       for (int i = 0; i < nums.size(); i++) {
          a[nums[i]] = i;
       }
       for (int i = 0; i < nums.size(); i++) {
          if (a.count(target-nums[i]) > 0 && a[target-nums[i]]!= i) {
              b[0] = i;
              b[1] = a[target - nums[i]] ;
              break;
          }
       }

       return b;
    }
};


void Test()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution *sln = new Solution();
    vector<int> res;
    res = sln->twoSum(nums,target);
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout <<endl;
}

int main()
{
    Test();
    return 0;
}