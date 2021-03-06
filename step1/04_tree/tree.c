//---------------------------------------
// 树
//---------------------------------------
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TNode *Position;
//typedef Position BinTree; /* 二叉树类型 */
typedef struct TNode *BinTree;
struct TNode{ /* 树结点定义 */
    ElementType Data; /* 结点数据 */
    BinTree Left;     /* 指向左子树 */
    BinTree Right;    /* 指向右子树 */
};

//---------------------------------------
// 中序遍历
//---------------------------------------
void InorderTraversal( BinTree BT )
{
    if( BT ) {
        InorderTraversal( BT->Left );
        /* 此处假设对BT结点的访问就是打印数据 */
        printf("%d ", BT->Data); /* 假设数据为整型 */
        InorderTraversal( BT->Right );
    }
}
 
//---------------------------------------
// 前序遍历
//---------------------------------------
void PreorderTraversal( BinTree BT )
{
    if( BT ) {
        printf("%d ", BT->Data );
        PreorderTraversal( BT->Left );
        PreorderTraversal( BT->Right );
    }
}
 
//---------------------------------------
// 后序遍历
//---------------------------------------
void PostorderTraversal( BinTree BT )
{
    if( BT ) {
        PostorderTraversal( BT->Left );
        PostorderTraversal( BT->Right );
        printf("%d ", BT->Data);
    }
}
 
//---------------------------------------
// 层级遍历
//---------------------------------------
// void LevelorderTraversal ( BinTree BT )
// { 
//     Queue Q; 
//     BinTree T;
//  
//     if ( !BT ) return; /* 若是空树则直接返回 */
//      
//     Q = CreatQueue(); /* 创建空队列Q */
//     AddQ( Q, BT );
//     while ( !IsEmpty(Q) ) {
//         T = DeleteQ( Q );
//         printf("%d ", T->Data); /* 访问取出队列的结点 */
//         if ( T->Left )   AddQ( Q, T->Left );
//         if ( T->Right )  AddQ( Q, T->Right );
//     }
// }
//---------------------------------------
//查找（尾递归）
//---------------------------------------
Position Find(BinTree BST,ElementType X)
{
    if ( !BST )
    {
        return NULL;
    }

    if ( X > BST->Data)
    {
        return Find(BST->Right,X);
    }
    else if ( X < BST->Data)
    {
        return Find(BST->Left,X);
    }
    else
    {
        return BST;
    }
}
 
//---------------------------------------
//查找（非递归方式）
//---------------------------------------
Position IterFind(BinTree BST, ElementType X)
{
    while( BST){
        if ( X > BST->Data)
        {
            BST = BST->Right;
        } else if( X < BST->Data)
        {
            BST = BST->Left;
        } else /*X == BST->Data*/
        {
            return BST;  //查找成功，返回找到节点的位置
        }
    }
    return NULL;
}

//---------------------------------------
//查找最小元素
//---------------------------------------
Position FindMin(BinTree BST)
{
    if ( !BST )
    {
        return NULL;
    }
    else if( ! BST->Left ) //如果没有儿子
    {
         return BST; //如果节点没有左儿子，该节点元素就是最小的    
    }
    else  //如果有左儿子,沿左分支继续查询
    {
        return FindMin(BST->Left); 
    }
}

//---------------------------------------
//查找最大元素
//---------------------------------------
Position FindMax(BinTree BST)
{
    if ( !BST )
    {
        return NULL;
    }
    else if( ! BST->Right) //节点没有右儿子,该节点就是最大值
    {
        return BST;
    }
    else
    {
        return FindMax(BST->Right);
    }
}

//---------------------------------------
// 插入元素
//---------------------------------------
BinTree Insert( BinTree BST, ElementType X )
{
    if( !BST ){ /* 若原树为空，生成并返回一个结点的二叉搜索树 */
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    } else if( X < BST->Data ){
            BST->Left = Insert( BST->Left, X );   /*递归插入左子树*/
    } else if( X > BST->Data ){
            BST->Right = Insert( BST->Right, X ); /*递归插入右子树*/
    }
        /* else X已经存在，什么都不做 */
    return BST;
}

//---------------------------------------
// 删除元素
//---------------------------------------
BinTree Delete( BinTree BST, ElementType X ) 
{ 
    Position Tmp; 
 
    if( !BST ) 
        printf("要删除的元素未找到"); 
    else {
        if( X < BST->Data ) 
            BST->Left = Delete( BST->Left, X );   /* 从左子树递归删除 */
        else if( X > BST->Data ) 
            BST->Right = Delete( BST->Right, X ); /* 从右子树递归删除 */
        else { /* BST就是要删除的结点 */
            /* 如果被删除结点有左右两个子结点 */ 
            if( BST->Left && BST->Right ) {
                /* 从右子树中找最小的元素填充删除结点 */
                Tmp = FindMin( BST->Right );
                BST->Data = Tmp->Data;
                /* 从右子树中删除最小元素 */
                BST->Right = Delete( BST->Right, BST->Data );
            }
            else { /* 被删除结点有一个或无子结点 */
                Tmp = BST; 
                if( !BST->Left )       /* 只有右孩子或无子结点 */
                    BST = BST->Right; 
                else                   /* 只有左孩子 */
                    BST = BST->Left;
                free( Tmp );
            }
        }
    }
    return BST;
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
void visualization(BinTree tree, char* filename)
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

BinTree CreateTreeNode(ElementType x) //创建节点
{
    BinTree BT;
    BinTree node = (BinTree )malloc(sizeof(struct TNode));
    node->Data = x;
    node->Left = NULL;
    node->Right = NULL;

    Insert(BT,x);
    return node;
}

void test_insert(){
    BinTree BT = (BinTree)malloc(sizeof(struct TNode));
    BT->Data = 10;

    Insert(BT,4);
    Insert(BT,3);
    Insert(BT,1);
    Insert(BT,2);
    Insert(BT,5);
    Insert(BT,11);
    Insert(BT,15);
    Insert(BT,12);
    Insert(BT,16);

    char* filename = "bst.dot";
    visualization(BT, filename);

    printf("\n Preorder Traversal ------------------\n");
    PreorderTraversal(BT);
    printf("\n");

    printf("\n Inorder Traversal ------------------\n");
    InorderTraversal(BT);
    printf("\n");

    printf("\n Postorder Traversal ------------------\n");
    PostorderTraversal(BT);
    printf("\n");
}
int main(){
    test_insert();
    //printf("\n----------------删除操作--------------\n");
    //Delete(BT,1);
    //Delete(BT,2);
    //Delete(BT,3);
    //printf("\nInorder Traversal ------------------\n");
    //InorderTraversal(BT);
    return 0;
}
