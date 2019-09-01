#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct AVLNode *Position;
typedef Position AVLTree; /* AVL树类型 */
typedef int ElementType;
struct AVLNode{
    ElementType Data; /* 结点数据 */
    AVLTree Left;     /* 指向左子树 */
    AVLTree Right;    /* 指向右子树 */
    int Height;       /* 树高 */
};
 
int Max ( int a, int b )
{
    return a > b ? a : b;
}

//L 
AVLTree SingleLeftRotation ( AVLTree A )
{ /* 注意：A必须有一个左子结点B */
  /* 将A与B做左单旋，更新A与B的高度，返回新的根结点B */     
 
    AVLTree B = A->Left;
    A->Left = B->Right;
    B->Right = A;
    A->Height = Max( GetHeight(A->Left), GetHeight(A->Right) ) + 1;
    B->Height = Max( GetHeight(B->Left), A->Height ) + 1;
  
    return B;
}

//LR ROTATION 
AVLTree DoubleLeftRightRotation ( AVLTree A )
{ /* 注意：A必须有一个左子结点B，且B必须有一个右子结点C */
  /* 将A、B与C做两次单旋，返回新的根结点C */
     
    /* 将B与C做右单旋，C被返回 */
    A->Left = SingleRightRotation(A->Left);
    /* 将A与C做左单旋，C被返回 */
    return SingleLeftRotation(A);
}
 
/*************************************/
/* 对称的右单旋与右-左双旋请自己实现 */
/*************************************/
 
AVLTree Insert( AVLTree T, ElementType X )
{ /* 将X插入AVL树T中，并且返回调整后的AVL树 */
    if ( !T ) { /* 若插入空树，则新建包含一个结点的树 */
        T = (AVLTree)malloc(sizeof(struct AVLNode));
        T->Data = X;
        T->Height = 0;
        T->Left = T->Right = NULL;
    } /* if (插入空树) 结束 */
 
    else if ( X < T->Data ) {
        /* 插入T的左子树 */
        T->Left = Insert( T->Left, X);
        /* 如果需要左旋 */
        if ( GetHeight(T->Left)-GetHeight(T->Right) == 2 )
            if ( X < T->Left->Data ) 
               T = SingleLeftRotation(T);      /* 左单旋 */
            else 
               T = DoubleLeftRightRotation(T); /* 左-右双旋 */
    } /* else if (插入左子树) 结束 */
     
    else if ( X > T->Data ) {
        /* 插入T的右子树 */
        T->Right = Insert( T->Right, X );
        /* 如果需要右旋 */
        if ( GetHeight(T->Left)-GetHeight(T->Right) == -2 )
            if ( X > T->Right->Data ) 
               T = SingleRightRotation(T);     /* 右单旋 */
            else 
               T = DoubleRightLeftRotation(T); /* 右-左双旋 */
    } /* else if (插入右子树) 结束 */
 
    /* else X == T->Data，无须插入 */
 
    /* 别忘了更新树高 */
    T->Height = Max( GetHeight(T->Left), GetHeight(T->Right) ) + 1;
     
    return T;
}
void write2dot(BinTree tree, FILE* fw)
{
	if(tree == NULL)
		return ;
	else
	{
		fprintf(fw, "%d [label = \"<f0> | <f1> %d | <f2> \", color = green, fontcolor = black, style = filled];\n", tree->Data, tree->Data);
	}
	if(tree->Left)
	{
		fprintf(fw, "%d [label = \"<f0> | <f1> %d | <f2> \", color = green, fontcolor = black, style = filled];\n", tree->Left->Data, tree->Left->Data);
		fprintf(fw, "%d:f0:sw -> %d:f1;\n", tree->Data, tree->Left->Data);
	}
	if(tree->Right)
	{
		fprintf(fw, "%d [label = \"<f0> | <f1> %d | <f2> \", color = green, fontcolor = black, style = filled];\n", tree->Right->Data, tree->Right->Data);
		fprintf(fw, "%d:f2:se -> %d:f1;\n", tree->Data, tree->Right->Data);
	}
	write2dot(tree->Left, fw);
	write2dot(tree->Right, fw);
}
void visualization(AVLTree tree, char* filename)
{
	FILE *fw;
	if( NULL == (fw = fopen(filename, "w")) )
	{
		printf("open file error");
		exit(0);
	}
	fprintf(fw, "digraph\n{\nnode [shape = Mrecord, style = filled, color = green, fontcolor = black];\n");
	write2dot(tree, fw);
	fprintf(fw, "}");
	fclose(fw);
}
void test_LRotation(){
    AVLTree BBTree = (AVLTree) malloc(sizeof(struct AVLNode));
    BBTree->Data = 10;
    Insert(BBTree,4);
    Insert(BBTree,3);
    char *filename = "bbt.dot";
    visualization(BBTree, filename);
}

void test_LRRotation(){

}
int main(){
    test_LRotation();
    return 0;

}