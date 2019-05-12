# ACM Basic

<!-- TOC -->

- [ACM Basic](#acm-basic)
    - [List](#list)
    - [Stack](#stack)
    - [Queue](#queue)
    - [Dynamic Programming](#dynamic-programming)
        - [longest_common_sequence  最长公共子序列问题](#longest_common_sequence--最长公共子序列问题)
        - [sum_equal_n  从一堆数字中，选择几个，使得能够拼出和为sum的个数。](#sum_equal_n--从一堆数字中选择几个使得能够拼出和为sum的个数)
        - [interval_sum_max 从一堆数字中，任选几个不相邻的数字，使得求和最大。](#interval_sum_max-从一堆数字中任选几个不相邻的数字使得求和最大)
        - [package_problem 背包问题.](#package_problem-背包问题)

<!-- /TOC -->
## List

线性表: 
- 建立空表 MakeEmpty
- 查找元素 Find
- 插入元素 Insert
- 删除元素 Delete

$cd acm/step1/00_list/
gcc List.c
./a.out

```bash
[Insert]before location 1 Success, PtrL->Last :0
[Insert]before location 2 Success, PtrL->Last :1
[Insert]before location 3 Success, PtrL->Last :2
[Insert]before location 4 Success, PtrL->Last :3
[Insert]before location 5 Success, PtrL->Last :4
[Insert]before location 6 Success, PtrL->Last :5
[Insert]before location 7 Success, PtrL->Last :6
[Insert]before location 8 Success, PtrL->Last :7
[Insert]before location 9 Success, PtrL->Last :8
[Insert]before location 10 Success, PtrL->Last :9
[Insert]PtrL->Last is 9,List is Full, Insert Failed!
[Print]data 0: 1
[Print]data 1: 2
[Print]data 2: 3
[Print]data 3: 4
[Print]data 4: 5
[Print]data 5: 6
[Print]data 6: 7
[Print]data 7: 8
[Print]data 8: 9
[Print]data 9: 10
[Delete]before location 10 Success,PtrL->Last :8
[Delete]before location 9 Success,PtrL->Last :7
[Delete]before location 8 Success,PtrL->Last :6
[Delete]before location 7 Success,PtrL->Last :5
[Delete]before location 6 Success,PtrL->Last :4
[Delete]before location 5 Success,PtrL->Last :3
[Delete]before location 4 Success,PtrL->Last :2
[Delete]before location 3 Success,PtrL->Last :1
[Delete]before location 2 Success,PtrL->Last :0
[Delete]before location 1 Success,PtrL->Last :-1
[Delete]Location is illegal,Delete Failed
```

## Stack

push()  压栈  
pop()   弹栈

查看栈顶元素 top()

## Queue

push()  压入队列  
pop()   弹出队列
查看队首元素 front()

## Dynamic Programming

动态规划可以认为是剪枝的递归算法

### longest_common_sequence  最长公共子序列问题
问题描述
```bash
n = 6
m = 6
s = "abcdec"
t = "becdce"
最长公共子子序列为: bcde
```
### sum_equal_n  从一堆数字中，选择几个，使得能够拼出和为sum的个数。
求和等于A值问题
```bash
从一堆数字中选择几个，使得能够拼出和为SUM的数
arr = [3,34,4,12,5,2]
Sum = 9
选择arr[i]
```

### interval_sum_max 从一堆数字中，任选几个不相邻的数字，使得求和最大。

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

### package_problem 背包问题. 
背包问题描述
```bash
n = 4
w = 2, 1, 3, 2
v = 3, 2, 4, 2
W = 5
n个包裹，每个包裹的重量为w[i],价值为v[i],选择几个包裹，使得总重量为W，价值总和最高的方案
```

