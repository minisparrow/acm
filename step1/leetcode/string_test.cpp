#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string string_;
    string newString;
    stack<char> stk;
    stack<char> stk2;
    const char* p = " ";
    const char* end = ".";
    char* pp = const_cast<char*>(p);
    char* pend = const_cast<char*>(end);
    getline(cin,string_);
    //字符转换，非字母的符号都换做“ ”,除了结尾的“.”不换。
    for(int i = 0 ; i < string_.size(); i++){
        if( isalpha(string_[i])){
           newString.push_back(string_[i]); 
        }
        else if(i == string_.size()-1 && string_[i] == *pend){
           newString.push_back(string_[i]); 
        }
        else {
            newString.push_back(*pp);
        }
    }
    //压栈规则
    for(int i = 0 ; i < newString.size(); i++){
        char c = newString[i];
        //栈为空, 如果来了字母要大写。
        if (stk.empty()){
            if(isalpha(c)){
                stk.push(toupper(c));
            }
            else{
            }
        }
        //栈不为空
        else{
        //栈不为空, 如果栈顶为空格，判断来的字符,
        //如果来的字符为空格，不做操作，
        //如果来的字符是字母，则大写压栈
            if (stk.top() == *pp){
                if (c == *pp){
                } else {
                    stk.push(toupper(c));
                }
            }
        //栈不为空, 如果栈顶不是空格,要来的字符直接压入栈
            else {
                    stk.push(c);
            }
        }
    }

    while(!stk.empty()){
        char cc; 
        cc = stk.top();
        stk2.push(cc);
        stk.pop();
    }

    while(!stk2.empty()){
        char c2;
        c2 = stk2.top();
        cout << c2;
        stk2.pop();
    }
    cout << endl;
    return 0;
}
