#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    
    bool isSubsequence(string s, string t) {
       int i = 0;
       int tindex;
       while( i < s.size()){
           if(t.find(s[i]) != -1){
               tindex = t.find(s[i]);
               t = t.substr(tindex+1,t.size());
               i += 1;
           }
           else {
               return false;
           }
       }
       return true;
   }
   /*
      // dynamic programming
      bool isSubsequence(string s, string t) {
       int dp[s.size()+1][t.size()+1];
       if(s.size() == 0){
           return true;
       }
       if(t.size() == 0){
           return false;
       }
       if(s.size() > t.size()){
           return false;
       }
       for(int i = 0; i < s.size()+1 ; i++){
           for(int j = 0; j < t.size()+1 ; j++){
               if (i == 0){
                   dp[i][j] = 1;
               }
               else if (j == 0){
                   dp[i][j] = 0;
               }
               else if (s[i-1] == t[j-1]){
                   dp[i][j] = dp[i-1][j-1];
               }
               else {
                   dp[i][j] = dp[i][j-1];
               }
           }
       }
       return dp[s.size()][t.size()];
   }
   */

};

/*
void test(){
    Solution* sln = new Solution();
    string s = "abc";
    string t = "ahbgdc";
    bool ans = sln->isSubsequence(s,t);
    cout << ans << endl;
    cout << s << endl << t << endl;
}
*/