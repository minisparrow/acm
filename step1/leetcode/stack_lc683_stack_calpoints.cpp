#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
// stack1 store all elems of scores
// stack2 store all elems of previous two sum
class Solution {
public:
    int calPoints(vector<string>& ops) {
       stack<int> stack1; 
       stack<int> stack2; 
       int sum = 0;
       char score; 

       for(int i=0; i<ops.size(); i++){
           if (ops[i] == "D"){
               int top = stack1.top();
               int elem = 2*top;
               stack2.push(elem+top);
               stack1.push(elem);
               sum += stack1.top();
           }
           else if (ops[i] == "C"){
               sum -= stack1.top();
               stack1.pop();
               stack2.pop();
           }
           else if (ops[i] == "+"){
               int top_stk1 = stack1.top();
               int top_stk2 = stack2.top();
               stack1.push(top_stk2);
               stack2.push(top_stk1 + top_stk2);
               sum += stack1.top();
           }
           else{
               int top_stk1;
               if (stack1.empty()){
                  top_stk1 = 0;
               }
               else{
                  top_stk1 = stack1.top();
               }
               int elem = atoi(ops[i].c_str());
               stack1.push(elem);
               stack2.push(elem+top_stk1);
               sum += stack1.top();
           }
       }

       return sum;
    }
};

int main(){
   Solution* sln = new Solution();
   vector<string> ops{"5","-2","4","C","D","9","+","+"};
   int ans;
   ans = sln->calPoints(ops);
   cout<< ans << endl;
   return 0;
}
