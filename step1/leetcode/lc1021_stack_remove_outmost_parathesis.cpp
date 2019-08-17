#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        stack<char> stk;
        vector<int> outerMark;
        string ans;
        for (int i = 0; i < S.size(); i++)
        {
            char s = S[i];
            if (s == '('){
                if (stk.empty()){
                    outerMark.push_back(i);
                }
                stk.push(s);
            }
            else if(s == ')'){
                stk.pop();
                if (stk.empty()){
                    outerMark.push_back(i);
                }
            }
        }
        for (int j = 0; j < outerMark.size(); j++){
            cout<< outerMark[j] <<endl;
        }

        vector<int>::iterator it;

        for (int i = 0; i < S.size(); i++){
            it = find(outerMark.begin(),outerMark.end(),i);// 判断i是否在outerMark里
            if(it == outerMark.end()){ //如果i 不在outerMark中就压入ans 的string中。
                ans.push_back(S[i]);
            }
            
        }
        return ans;
    }
    string removeOuterParentheses2(string S) {
        stack<char> stk;
        string ans;
        int num = 1;
        // 跳过第0个元素，从第1个元素开始计数，是（ 计数加1,是) 计数减1。 计数>0 表示是中间的括号。 
        // 计数为0时表示一个外括号结束。计数设为1且遍历元素时跳过下一个元素，下一个元素肯定是一个外括号。
        for (int i = 1; i < S.size(); i++)
        {
            if(S[i] == '('){
                num++;
            }
            else{
                num--;
            }
            if (num > 0)
            {
                /* code */
                ans.push_back(S[i]);
            }
            else{
                num = 1;
                i++;
            }
            
        }

        return ans;
    }
};

int main()
{
    Solution* sln = new Solution();
    string str = "(()())(())";
    string ans;
    ans = sln->removeOuterParentheses2(str);
    cout << ans <<endl;
    return 0;

}