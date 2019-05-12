# 1. ACM Basic

<!-- TOC -->

- [1. ACM Basic](#1-acm-basic)
    - [1.1. Reference](#11-reference)
    - [1.2. List](#12-list)
        - [1.2.1. 数组存储线性表](#121-数组存储线性表)
        - [1.2.2. 链式存储线性表](#122-链式存储线性表)
    - [1.3. Stack](#13-stack)
    - [1.4. Queue](#14-queue)
    - [1.5. Dynamic Programming](#15-dynamic-programming)
        - [1.5.1. longest_common_sequence  最长公共子序列问题](#151-longest_common_sequence--最长公共子序列问题)
        - [1.5.2. sum_equal_n  从一堆数字中，选择几个，使得能够拼出和为sum的个数。](#152-sum_equal_n--从一堆数字中选择几个使得能够拼出和为sum的个数)
        - [1.5.3. interval_sum_max 从一堆数字中，任选几个不相邻的数字，使得求和最大。](#153-interval_sum_max-从一堆数字中任选几个不相邻的数字使得求和最大)
        - [1.5.4. package_problem 背包问题.](#154-package_problem-背包问题)

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

```bash
typedef struct LNode *PtrToLNode;
struct LNode {
    int Data;
    PtrToLNode Next;
}
```

- Find
- Insert
- Delete

## 1.3. Stack

push()  压栈  
pop()   弹栈

查看栈顶元素 top()

## 1.4. Queue

push()  压入队列  
pop()   弹出队列
查看队首元素 front()

## 1.5. Dynamic Programming

动态规划可以认为是剪枝的递归算法

### 1.5.1. longest_common_sequence  最长公共子序列问题
问题描述
```bash
n = 6
m = 6
s = "abcdec"
t = "becdce"
最长公共子子序列为: bcde
```
### 1.5.2. sum_equal_n  从一堆数字中，选择几个，使得能够拼出和为sum的个数。
求和等于A值问题
```bash
从一堆数字中选择几个，使得能够拼出和为SUM的数
arr = [3,34,4,12,5,2]
Sum = 9
选择arr[i]
```

### 1.5.3. interval_sum_max 从一堆数字中，任选几个不相邻的数字，使得求和最大。

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

### 1.5.4. package_problem 背包问题. 
背包问题描述
```bash
n = 4
w = 2, 1, 3, 2
v = 3, 2, 4, 2
W = 5
n个包裹，每个包裹的重量为w[i],价值为v[i],选择几个包裹，使得总重量为W，价值总和最高的方案
```

