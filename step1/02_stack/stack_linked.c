//---------------------------------------
// 链表实现堆栈stack
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
typedef struct StackNode *PtrToStackNode;
struct StackNode {
    ElementType Data; 
    PtrToStackNode Next; //Point to Next Node
};

typedef PtrToStackNode Stack;
 
Stack CreateStack( int MaxSize )
{
    Stack S = (Stack)malloc(sizeof(struct StackNode));
    S->Next = NULL;  //构建栈的头节点
    return S;
}
 
bool IsEmpty( Stack S )
{
    return (S->Next == NULL);
}
 
bool Push( Stack S, ElementType X )
{   
    //------------------------------
    //链表头节点插入元素
    //------------------------------
    //1. 先建立一个插入元素的临时节点tmpCell
    //2. 该临时节点插入到链表的末尾
    // S  ->   [S->Next]
    // [Insert] tmpCell
    // S  -> tmpCell ->  [S->Next]

    PtrToStackNode tmpCell = (PtrToStackNode) malloc(sizeof(struct StackNode));
    tmpCell->Data = X;
    tmpCell->Next = S->Next;
    S->Next = tmpCell;
    printf("[Push]Success.\n");
    return true;
}
 
 
ElementType Pop( Stack S )
{
    if ( IsEmpty(S) ) {
        printf("[Pop]Failed, Stack is Empty.\n");
        return false; /* ERROR是ElementType的特殊值，标志错误 */
    }
    else {
        //------------------------------
        //链表头节点删除元素
        //------------------------------
        // S  ->  [S->Next] -> S->Next->Next
        // Delete
        // S  ->  S->Next->Next
        PtrToStackNode tmpCell = S->Next;
        ElementType tmpData = tmpCell->Data;

        S->Next = tmpCell->Next;
        free(tmpCell);
        printf("[Pop]Success.\n");
        return  tmpData;
    }
}

ElementType Top( Stack S )
{
    if ( IsEmpty(S) ) {
        printf("[Top]Failed, Stack is Empty.\n");
        return false; /* ERROR是ElementType的特殊值，标志错误 */
    }
    else {
        printf("[Top]Success, Top Element is %d\n",S->Next->Data);
        return ( S->Next->Data ); 
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
