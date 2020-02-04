#include <iostream>
#include <deque>
using namespace std;

/*
queue
deque<int> que;
que.push_back()
que.pop_back()
que.push_front()
que.pop_front()

stack
stack<int> stk; 
stk.push(int);
stk.pop();
stk.top();

*/

class MyStack {
public:
    deque<int> que;
    /** Initialize your data structure here. */
    MyStack() {
    }

    /** Push element x onto stack. */
    void push(int x) {
        que.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int elem = *(que.end()-1);
        que.pop_back(); 
        return elem;
    }
    
    /** Get the top element. */
    int top() {
        return *(que.end()-1);
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
};

int main()
{
 MyStack* obj = new MyStack();
 obj->push(1);
 int elem = obj->top();
 cout << elem << endl;

 obj->push(2);
 elem = obj->top();
 cout << elem << endl;

 obj->push(3);
 elem = obj->top();
 cout << elem << endl;

 obj->pop();
 obj->pop();
 elem = obj->top();
 cout << elem << endl;
 return 0;
}
 