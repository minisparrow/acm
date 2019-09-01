#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // slowest
    string removeDuplicates(string S) {
        stack<char> stk;
        for (int i = 0; i < S.size(); i++){
            if( !stk.empty() && S[i] == stk.top()){
                stk.pop();
            }
            else{
                stk.push(S[i]);
            }
        }
        string ans;
        while (!stk.empty())
        {
            char s = stk.top();
            stk.pop();
            ans.insert(ans.begin(),s);
        }
        return ans; 
    }

    //more faster 
    string removeDuplicates2(string S) {
        stack<char> stk;
        string ans;
        for (int i = 0; i < S.size(); i++){
            if( !stk.empty() && S[i] == stk.top()){
                stk.pop();
                ans.pop_back();
            }
            else{
                stk.push(S[i]);
                ans.push_back(S[i]);
            }
        }
        return ans; 
    }

    // more saving memeoy
    string removeDuplicates3(string S) {
        string ans;
        for (int i = 0; i < S.size(); i++){
            if( !ans.empty() && S[i] == ans.back() ) {
                ans.pop_back();
            }
            else{
                ans.push_back(S[i]);
            }
        }
        return ans; 
    }
};

int main(){
    Solution* sln = new Solution();
    string S = "abbaca";
    string ans;
    ans = sln->removeDuplicates3(S);
    cout << ans <<endl;
    return 0;
}