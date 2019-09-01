# stack1 store all elems of scores
# stack2 store all elems of previous two sum
class Solution(object):
    def calPoints(self,ops):
        stack1 = []
        stack2 = []
        sum = 0
        for score in ops:
            if score == 'D':
                top = stack1[-1]
                elem = 2*top 
                stack2.append(elem+top) # sum of previous 2 elems
                stack1.append(elem)
                sum += stack1[-1]
            elif score == 'C':
                sum -= stack1[-1]
                stack1.pop()
                stack2.pop()
            elif score == '+':
                top_stk1 = stack1[-1]
                top_stk2 = stack2[-1]
                stack1.append(top_stk2)
                stack2.append(top_stk1 + top_stk2) # sum of previous 2 elems
                sum += stack1[-1]
            else:
                if stack1 == []:
                    top_stk1 = 0 
                else:
                    top_stk1 = stack1[-1]
                stack1.append(int(float(score)))
                stack2.append(int(float(score))+top_stk1)
                sum += stack1[-1]
        return sum
                    

if __name__ == '__main__':
    sln = Solution() 
    ops = ["5","-2","4","C","D","9","+","+"]
    ans = sln.calPoints(ops)
    print(ans)