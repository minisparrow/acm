#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

   int climbStairs(int n) {
      vector<int> f(n);
      for(int i = 0; i < n; i++){
          if (i != 0 && i != 1){
              f[i] = f[i-1] + f[i-2];
          }
          else if (i == 1){
              f[i] = 2;
          }
          else if (i == 0){
              f[i] = 1;
          }
      }

      return f[n-1];
   }
};
