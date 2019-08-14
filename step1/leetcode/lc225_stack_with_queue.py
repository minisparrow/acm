class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.topindex = -1
        self.element = []
        

    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.topindex += 1
        self.element.append(x)

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        if self.topindex != -1:
            elem = self.element.pop()
            self.topindex -= 1
            return elem
        else:
            return None
                    
    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        if self.topindex == -1:
            return None
        else:
            return self.element[self.topindex]
    
    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        if self.topindex == -1:
            return True 
        else:
            return False      


# Your MyStack object will be instantiated and called as such:
obj = MyStack()
obj.push(1)
obj.push(2)
obj.push(3)
param_2 = obj.pop()
param_2 = obj.pop()
param_2 = obj.pop()
param_3 = obj.top()
param_4 = obj.empty()

print(param_2)
print(param_3)
print(param_4)