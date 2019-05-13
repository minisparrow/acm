#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct LNode *PtrToLNode;
struct LNode {
    int Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
 
/* 查找 */
#define ERROR NULL

//Find Kth Element in List L
List FindKth( int K,List L)
{
    List p = L; 
    int i = 1; 
    while (p != NULL && i < K)
    {
        p = p->Next;
        i++;
    }
    if (i == K) {
        printf("[FindKth]Success. Kth element is  %d\n",p->Data); 
        return p;
    } else {
        printf("[FindKth]Failed.\n"); 
        return NULL;
    }
}

//Find X element in List  
Position Find( List L, int X )
{
    Position p = L; /* p指向L的第1个结点 */
 
    while ( p && p->Data!=X )
        p = p->Next;
 
    /* 下列语句可以用 return p; 替换 */
    if (p != NULL){
        printf("[Find]Success.\n"); 
        return p;
    } else {
        printf("[Find]Failed.\n"); 
        return ERROR;
    }
}
 
/* 带头结点的插入 */
/*注意:在插入位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是链表结点指针，在P之前插入新结点 */
bool Insert( List L, int X, Position P )
{ /* 这里默认L有头结点 */
    Position tmp, pre;

    //思路
    //1. 先找到要插入节点P之前的节点pre
    //2. 再在节点pre之后插入元素X

    /*1. 查找P的前一个结点 */        
    for ( pre=L; pre != NULL && pre->Next != P; pre = pre->Next );            

    if ( pre==NULL ) { /* P所指的结点不在L中 */
        printf("[Insert]Failed.\n");
        return false;
    }
    else { /* 找到了P的前一个结点pre */
        /* 2.在P前插入新结点 */
        tmp = (Position)malloc(sizeof(struct LNode)); /* 申请、填装结点 */
        tmp->Data = X; 
        //插入节点的关键代码
        tmp->Next = P;
        pre->Next = tmp;
        printf("[Insert] %d Success.\n",X);
        return true;
    }
}
 
/* 带头结点的删除 */
/*注意:在删除位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是拟删除结点指针 */
bool Delete( List L, Position P )
{ /* 这里默认L有头结点 */
    Position tmp, pre;

    //思路
    //1. 先找到要插入节点P之前的节点pre
    //2. 再在节点pre之后插入元素X

    /* 1.查找P的前一个结点 */        
    /* 从List头开始，逐一向后查询，如果下个节点不是空，且节点不等于查询的P时，找下一个节点 */
    for ( pre = L; pre != NULL && pre->Next != P; pre = pre->Next ) ;            

    if ( pre==NULL || P==NULL) { /* P所指的结点不在L中 */
        printf("[Delete]Failed.\n");
        return false;
    }
    else { /* 找到了P的前一个结点pre */
        /* 将P位置的结点删除 */
        pre->Next = P->Next;
        free(P);
        printf("[Delete]Success.\n");
        return true;
    }
}

int main(){
    List L,P= NULL;
    int idx;
    L->Data = 0;
    L->Next = P;
    Insert(L,1,P);
    Insert(L,2,P);
    Insert(L,3,P);
    Insert(L,4,P);
    Insert(L,5,P);
    Insert(L,6,P);
    Insert(L,7,P);
    Insert(L,8,P);

    for (List tmp = L,idx=0; tmp->Next != NULL; tmp = tmp->Next) {
        printf("[Print]  %d\n",  tmp->Data);
    }

    Find(L,5);
    FindKth(5,L);

    return 0;
}
