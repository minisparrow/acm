#include <iostream>
#include <vector>
using namespace std;

//idea: previous i rooms, get maximum money: f[i]
//rob room i: a: f[i]  = f[i-2] + nums[i]
//dont rob room i: b:  f[i] = f[i-1]
//f[i] = max(a,b)
//border condition :  f[0] = nums[0]
//border condition :  f[1] = max(nums[0],nums[1])
class Solution {
public:
   int rob(vector<int>& nums) {
       if (nums.size() == 0){
           return 0;
       }
       vector<int> f(nums.size());
       int a;
       int b;
       for(int i = 0; i < nums.size(); i++){
           if(i !=0 && i != 1){
               a = f[i-2] + nums[i];
               b = f[i-1];
               f[i] = max(a,b);
           }
           else if(i == 0){
               f[i] = nums[i];
           }
           else if (i == 1){
               f[i] = max(nums[0],nums[1]);
           }
       }
       return f[nums.size()-1];
   }
};

