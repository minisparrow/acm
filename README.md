# 1. ACM Basic
<!-- TOC -->

- [1. ACM Basic](#1-acm-basic)
    - [1.1. Reference](#11-reference)
    - [1.2. List](#12-list)
        - [1.2.1. 数组存储线性表](#121-数组存储线性表)
        - [1.2.2. 链式存储线性表](#122-链式存储线性表)
            - [1.2.2.1. 链表数据结构(c)](#1221-链表数据结构c)
            - [1.2.2.2. 节点(python)](#1222-节点python)
            - [1.2.2.3. 从数组中创建单向链表(lc83)](#1223-从数组中创建单向链表lc83)
            - [1.2.2.4. 从数组中创建单项环链表(lc141)](#1224-从数组中创建单项环链表lc141)
            - [1.2.2.5. 遍历链表的所有节点并打印](#1225-遍历链表的所有节点并打印)
    - [1.3. Stack](#13-stack)
        - [1.3.1. 做stack相关leetcode 题目的一个心得](#131-做stack相关leetcode-题目的一个心得)
        - [1.3.2. c++ 中stack的一些常用操作](#132-c-中stack的一些常用操作)
        - [1.3.3. 用数组实现stack](#133-用数组实现stack)
        - [1.3.4. 用链表实现stack](#134-用链表实现stack)
        - [1.3.5. 用队列实现stack(lc225)](#135-用队列实现stacklc225)
    - [1.4. Queue](#14-queue)
        - [1.4.1. 用stack 实现queue(lc232)](#141-用stack-实现queuelc232)
    - [1.5. Tree](#15-tree)
        - [1.5.1. 二叉树](#151-二叉树)
        - [1.5.2. 平衡二叉树](#152-平衡二叉树)
        - [1.5.3. 堆 heap](#153-堆-heap)
            - [1.5.3.1. 堆的抽象数据类型描述](#1531-堆的抽象数据类型描述)
    - [1.6. Dynamic Programming](#16-dynamic-programming)
        - [1.6.1. longest_common_sequence  最长公共子序列问题](#161-longest_common_sequence--最长公共子序列问题)
        - [1.6.2. sum_equal_n  从一堆数字中，选择几个，使得能够拼出和为sum的个数。](#162-sum_equal_n--从一堆数字中选择几个使得能够拼出和为sum的个数)
        - [1.6.3. interval_sum_max 从一堆数字中，任选几个不相邻的数字，使得求和最大。](#163-interval_sum_max-从一堆数字中任选几个不相邻的数字使得求和最大)
        - [1.6.4. package_problem 背包问题.](#164-package_problem-背包问题)
    - [1.7. leetcode](#17-leetcode)
        - [数据结构](#数据结构)
        - [算法](#算法)
    - [1.8. python 函数与 c++ 函数功能对应](#18-python-函数与-c-函数功能对应)
        - [1.8.1. list后加入元素a](#181-list后加入元素a)
        - [1.8.2. list子串[a:b)](#182-list子串ab)
        - [最大直，最小直](#最大直最小直)
    - [c++ 数据结构常用api](#c-数据结构常用api)

<!-- /TOC -->

## 1.1. Reference
1. [浙大DSA](https://www.icourse163.org/learn/ZJU-93001?tid=1003997005#/learn/content)
## 1.2. List

### 1.2.1. 数组存储线性表

```bash
struct LNode{
    int Data[MAXSIZE];
    int Last;
};
```

- 建立空表 MakeEmpty
- 查找元素 Find
- 插入元素 Insert
- 删除元素 Delete

### 1.2.2. 链式存储线性表

#### 1.2.2.1. 链表数据结构(c)
   ```bash
   typedef struct LNode *PtrToLNode;
   struct LNode {
       int Data;
       PtrToLNode Next;
   }
   ```

#### 1.2.2.2. 节点(python)
   ```
   class ListNode(object):
       def __init__(self, x):
           self.val = x
           self.next = None
   ```
#### 1.2.2.3. 从数组中创建单向链表(lc83)
   ```
   def create_linklist(list_elems):
       node = ListNode(0)
       node_ret = node
       for i in list_elems: 
           tmp = ListNode(i)
           node.next = tmp
           node = node.next
       return node_ret.next
   ```

#### 1.2.2.4. 从数组中创建单项环链表(lc141)
   ```
   def create_cycle_linklist(list_elems,pos):
       node = ListNode(0)
       node_ret = node
       # 先构建链表从头到尾
       for i in list_elems: 
           tmp = ListNode(i)
           node.next = tmp
           node = node.next

       # 再来连接环的节点
       start = node_ret.next 
       if pos != -1:
          for i in range(0,len(list_elems)):
              node_ret = node_ret.next
              if i == pos:
                  break
          node.next = node_ret
       return start
   ```
#### 1.2.2.5. 遍历链表的所有节点并打印
   ```
   def transverse(node):
    node_list = []
    while node != None:
        node_list.append(node.val)
        node = node.next
    print(node_list)

   ```
   

## 1.3. Stack

Stack： 一种输入输出受限的线性表 FILO(First In Last Out)

### 1.3.1. 做stack相关leetcode 题目的一个心得
一定要先在草稿纸上画出具体的操作，想好每一个该怎么做。然后写代码就好写了。

### 1.3.2. c++ 中stack的一些常用操作
stack.push(val)
stack.pop()
stack.empty()

```bash
//---------------------------------------
// Stack structure,
//   |        |
//   |        |
//   |________|
//   |___4____|<--- Top
//   |___3____|
//   |___2____|
//   |___1____|
//--------------------------------------
```

### 1.3.3. 用数组实现stack
stack_array.c
```bash
typedef int ElementType;
typedef int Position;
struct StackNode {
        ElementType *Data; /* 存储元素的数组 */
        Position Top;      /* 栈顶指针 */
        int MaxSize;       /* 堆栈最大容量 */
};
typedef struct StackNode *Stack;
```

### 1.3.4. 用链表实现stack
stack_linked.c
```bash
typedef int ElementType;
typedef struct StackNode *PtrToStackNode;
struct StackNode {
    ElementType Data; 
    PtrToStackNode Next; //Point to Next Node
};

typedef PtrToStackNode Stack;
```
用链表实现的Stack，Push元素时，即插入时，插入到链表的头。删除时，删除链表的头元素
- 插入操作
```
//------------------------------
//链表头节点插入元素
//------------------------------
//1. 先建立一个插入元素的临时节点tmpCell
//2. 该临时节点插入到链表的末尾
//  ____________        ___________        ___________   
// | s | next   |----> | 0 | next  |----> | 1 | next  |
// |___|________|      |___|_______|      |___|_______|
// S  ->   [S->Next]
// [Insert] tmpCell
// S  -> tmpCell ->  [S->Next]

PtrToStackNode tmpCell = (PtrToStackNode) malloc(sizeof(struct StackNode));
tmpCell->Data = X;
tmpCell->Next = S->Next;
S->Next = tmpCell;
```

- 删除操作
```
//------------------------------
//链表头节点删除元素
//------------------------------
//  ____________        ___________        ___________   
// | s | next   |----> | 0 | next  |----> | 1 | next  |
// |___|________|      |___|_______|      |___|_______|
// S  ->  [S->Next] -> S->Next->Next
// Delete
// S  ->  S->Next->Next

PtrToStackNode tmpCell = S->Next;
ElementType tmpData = tmpCell->Data;
S->Next = tmpCell->Next;
free(tmpCell);
```

### 1.3.5. 用队列实现stack(lc225)

```
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

```


## 1.4. Queue

push()  压入队列  
pop()   弹出队列
查看队首元素 front()

### 1.4.1. 用stack 实现queue(lc232)

两个stack实现queue.
stk1用于push操作，stk2用于pop操作。

```
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
```

## 1.5. Tree 

### 1.5.1. 二叉树

- 树的建立
- 插入节点
- 删除节点
- 遍历节点
  - 二叉树的前序遍历 [lc144]
  - 二叉树的中序遍历 [lc94]
  - 二叉树的后序遍历 [lc145]
  - 二叉树的层次遍历,自顶向下 [lc102]
  - 二叉树的层次遍历,自底向上 [lc107]
  - 从前序和中序遍历序列构造树 [lc105]
  - 从后序和中序遍历序列构造树 [lc106]
  - 对称树 [lc101]
  - 相同树 [lc100]


### 1.5.2. 平衡二叉树

### 1.5.3. 堆 heap 
堆: 是优先队列(Priority Queue),特殊的队列。不是先入先出，而是按照元素的优先权（关键字）大小取出元素。

堆: 可以用优先队列的完全二叉树表示

最大堆(MaxHeap)，最小堆(MinHeap)

#### 1.5.3.1. 堆的抽象数据类型描述

- MaxHeap Create(int MaxSize)  创建一个空的最大堆
- IsFull(MaxHeap H)    最大堆是否已满
- IsEmpty(MaxHeap H) 最大堆是否已空
- Insert(MaxHeap H, ElementType item) 插入元素
- Delete(MaxHeap H, ElementType item) 删除元素

## 1.6. Dynamic Programming

动态规划可以认为是剪枝的递归算法

### 1.6.1. longest_common_sequence  最长公共子序列问题
问题描述
```bash
n = 6
m = 6
s = "abcdec"
t = "becdce"
最长公共子子序列为: bcde
```
### 1.6.2. sum_equal_n  从一堆数字中，选择几个，使得能够拼出和为sum的个数。
求和等于A值问题
```bash
从一堆数字中选择几个，使得能够拼出和为SUM的数
arr = [3,34,4,12,5,2]
Sum = 9
选择arr[i]
```

### 1.6.3. interval_sum_max 从一堆数字中，任选几个不相邻的数字，使得求和最大。

相邻数字求和最大问题描述
```bash
一堆数字中，任选几个不能相邻的数字，使得求和最大。
arr = [1,2,4,1,7,8,3]
求 max(Sum(arr[i])),i不相邻
```

动态规划与递归时间比较
```bash
$cd step1/2.3_dynamic_programming
$python interval_sum_max.py 
('recursive time:', 0.32363200187683105)
31
('dynamic time:', 0.0053958892822265625)
31.0
('times', 59.97750972074938)
```

### 1.6.4. package_problem 背包问题. 
背包问题描述
```bash
n = 4
w = 2, 1, 3, 2
v = 3, 2, 4, 2
W = 5
n个包裹，每个包裹的重量为w[i],价值为v[i],选择几个包裹，使得总重量为W，价值总和最高的方案
```


## 1.7. leetcode 

### 数据结构

数组
链表
二叉树
二叉搜索树
二叉平衡树
堆
栈
图

### 算法

各种排序算法
动态规划
贪心算法
递归算法




## 1.8. python 函数与 c++ 函数功能对应

从键盘输入一行以空格为分割符的数字，传给arr_数组.
Python
```python
arr_ = map(int,input().split())
arr_list = []
for i in arr_:
    arr_list.append(i)
```

C++
```c++
vector<int> arr_list;
string str_;
int n;
getline(cin,str_);
stringstream ss(str_);
while(ss>>n){
    arr_list.push_back(n);
} 

```

### 1.8.1. list后加入元素a
Python
```python
list_.append(a)
```

c++
```c++
list_.push_back(a)
```

### 1.8.2. list子串[a:b)
Python
```python
list_[a:b]
```
c++
```c++
vector<int> list_;
vector<int> list_sub(list_.begin()+a,list_.begin()+b);
```


### 最大直，最小直
Python
```python
max(list_)
min(list_)
```
c++
```c++
*max_element(vector_.begin(),vector_.end());
*min_element(vector_.begin(),vector_.end());
```

## c++ 数据结构常用api








