#include <iostream>
#include <vector>
#include <string>
#include <stack>
/*
1. string to int 
stoi(a string)

2. int to string
to_string(a int )

3. 判断一个string 是否是数字
比如 "9","-10","+"
string s;
s[0] >= '0' && s[0] <= '9' || s[0] == '-' && s.size() > 1

*/
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> stk;
        for( int i = 0 ; i < tokens.size(); i++) {
            if (tokens[i][0] >= '0' && tokens[i][0] <= '9' || tokens[i][0] == '-' && tokens[i].size() > 1) {
                stk.push(tokens[i]);
            } 
            else if (tokens[i] == "+") {
                int a = stoi(stk.top());
                stk.pop();
                int b = stoi(stk.top());
                stk.pop();
                int c = b + a;
                stk.push(to_string(c));
            }  
            else if (tokens[i] == "-") {
                int a = stoi(stk.top());
                stk.pop();
                int b = stoi(stk.top());
                stk.pop();
                int c = b - a;
                stk.push(to_string(c));
            }  
            else if (tokens[i] == "*") {
                int a = stoi(stk.top());
                stk.pop();
                int b = stoi(stk.top());
                stk.pop();
                int c = b * a;
                stk.push(to_string(c));
            }  
            else if (tokens[i] == "/") {
                int a = stoi(stk.top());
                stk.pop();
                int b = stoi(stk.top());
                stk.pop();
                int c = b / a;
                stk.push(to_string(c));
            }  
        }
        return stoi(stk.top());    
    }
};

int main()
{
     Solution *sln = new Solution();
     vector<string> tokens; 
     tokens = {"2","1","+","3","*"}; 
     int out = sln->evalRPN(tokens);
     cout << out << endl;
     return 0;
}