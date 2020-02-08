#include <stack>
#include <iostream>
class MyQueue {

private:
    std::stack<int> stk1;
    std::stack<int> stk2;

public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stk1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int front = peek();
        stk2.pop();
        return front;
    }
    
    /** Get the front element. */
    int peek() {
        int value;
        while(stk2.empty()){
            while(!stk1.empty()){
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        value = stk2.top();
        return value;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk1.empty() && stk2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(){
   MyQueue* obj = new MyQueue();
   int pop_value;
   for(int i = 0; i < 5; i++){
      obj->push(i);
   }
   for(int i = 0; i < 5; i++){
      pop_value = obj->pop();
      std::cout << pop_value << std::endl;
   }
   return 0;
}