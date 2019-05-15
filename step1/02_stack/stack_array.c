//---------------------------------------
// 数组实现堆栈stack
//---------------------------------------
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//---------------------------------------
// Stack structure,
//   |        |
//   |        |
//   |________|
//   |___4____|<--- Top
//   |___3____|
//   |___2____|
//   |___1____|
//---------------------------------------

typedef int ElementType;
typedef int Position;
struct StackNode {
        ElementType *Data; /* 存储元素的数组 */
        Position Top;      /* 栈顶指针 */
        int MaxSize;       /* 堆栈最大容量 */
};
typedef struct StackNode *Stack;
 
Stack CreateStack( int MaxSize )
{
        Stack S = (Stack)malloc(sizeof(struct StackNode));
        S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
        S->Top = -1;  //-1 表示stack is empty
        S->MaxSize = MaxSize;
        return S;
}
 
bool IsFull( Stack S )
{
        return (S->Top == S->MaxSize-1);
}

bool IsEmpty( Stack S )
{
        return (S->Top == -1);
}
 
bool Push( Stack S, ElementType X )
{
        if ( IsFull(S) ) {
            printf("[Push]Failed, Stack is Full.\n");
            return false;
        }
        else {
            S->Data[++(S->Top)] = X;
            printf("[Push]Success.\n");
            return true;
        }
}
 
 
ElementType Pop( Stack S )
{
        if ( IsEmpty(S) ) {
            printf("[Pop]Failed, Stack is Empty.\n");
            return false; /* ERROR是ElementType的特殊值，标志错误 */
        }
        else {
            printf("[Pop]Success.\n");
            return ( S->Data[(S->Top)--] ); 
        }
}

ElementType Top( Stack S )
{
        if ( IsEmpty(S) ) {
            printf("[Top]Failed, Stack is Empty.\n");
            return false; /* ERROR是ElementType的特殊值，标志错误 */
        }
        else {
            printf("[Top]Success, Top Element is %d\n",S->Data[S->Top]);
            return ( S->Data[S->Top] ); 
        }
}

int main(){ 
       Stack S = CreateStack(10); 
       Push(S,0);
       Push(S,1);
       Push(S,2);
       Push(S,3);
       Push(S,4);

       Top(S); //4
       Pop(S); 

       Top(S); //3
       Pop(S);

       Top(S); //2
       Pop(S);

       Top(S); //1
       Pop(S);

       Top(S); //0
       Pop(S);

       Top(S); //Empty
       Pop(S); //Empty
       return 0;
}
