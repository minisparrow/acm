#include <stdio.h>
#include <stdlib.h>

typedef struct LNode *List;
 
//const int MAXSIZE = 10;
#define MAXSIZE 10

// struct LNode data structure 
struct LNode{
    int Data[MAXSIZE];
    int Last;
};

// MakeEmpty
List MakeEmpty(){
     List PtrL;
     PtrL = (List) malloc(sizeof(struct LNode));
     PtrL->Last = -1;
     return PtrL;
}

// Find element x in List PtrL
int Find(int x, List PtrL){
    int i = 0;
    while (i <= PtrL->Last && PtrL->Data[i] != x) {
        i++;
    }
    if (i > PtrL->Last ) {
        return -1;
    }else {
        return i;
    }
}

//Insert x into PtrL at location i
void Insert(int x, int i, List PtrL){
    int j; 
    if ( PtrL->Last == MAXSIZE - 1)
    {
        printf("[Insert]PtrL->Last is %d,List is Full, Insert Failed!\n",PtrL->Last);
        return ;
    }
    //if (i < 1 || i > PtrL->Last + 1)
    if (i < 1 || i > MAXSIZE )
    {
        printf("[Insert]Location %d is illegal \n",i);
        return ;
    }
    for (j = PtrL->Last; j >= i-1; j-- )
    {
        /* move data from j to j+1,and left a space for i */
        PtrL->Data[j+1] = PtrL->Data[j];
    }
    PtrL->Data[i-1] = x; // element x put into location i-1;
    PtrL->Last++;
    printf("[Insert]before location %d Success, PtrL->Last :%d\n",i,PtrL->Last);
    return ;
}

//Delete element x at location i in List
void Delete(int i, List PtrL){
    int j; 
    if (i < 1 || i > PtrL->Last + 1)
    {
        printf("[Delete]Location is illegal,Delete Failed\n");
        return;
    }
    for (j = i; j <= PtrL->Last; j++ )
    {
        /* move data from j to j+1,and left a space for i */
        PtrL->Data[j-1] = PtrL->Data[j];
    }
    PtrL->Last--;
    printf("[Delete]before location %i Success,PtrL->Last :%d\n",i,PtrL->Last);
    return ;
}

int main(){
    List PtrL = MakeEmpty();
    Insert(1,1,PtrL);
    Insert(2,2,PtrL);
    Insert(3,3,PtrL);
    Insert(4,4,PtrL);
    Insert(5,5,PtrL);
    Insert(6,6,PtrL);
    Insert(7,7,PtrL);
    Insert(8,8,PtrL);
    Insert(9,9,PtrL);
    Insert(10,10,PtrL);
    Insert(11,11,PtrL);

    for (int i = 0; i < PtrL->Last+1 ; i++)
    {
        printf("[Print]data %d: %d\n",i,PtrL->Data[i]);
    }

    Delete(10,PtrL);
    Delete(9,PtrL);
    Delete(8,PtrL);
    Delete(7,PtrL);
    Delete(6,PtrL);
    Delete(5,PtrL);
    Delete(4,PtrL);
    Delete(3,PtrL);
    Delete(2,PtrL);
    Delete(1,PtrL);
    Delete(0,PtrL);

    return 0;
}