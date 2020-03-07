#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <iostream>
#include <map>
#include <list>
using namespace std;
/* 图的邻接表表示法 */
/*
4 6 1
1 2 2
2 3 2
1 3 5
2 4 1
3 4 3
1 4 4
*/
 
#define MaxVertexNum 100    /* 最大顶点数设为100 */
#define inf 65535  
typedef int Vertex;         /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;        /* 边的权值设为整型 */
typedef char DataType;        /* 顶点存储的数据类型设为字符型 */
int nVertex = 4;
int nEdge;
int startVertex;
int dist[MaxVertexNum];

// Visited[]为全局变量，已经初始化为false 

bool Visited[MaxVertexNum];

/* 边的定义 */
struct ENode{
    Vertex V1, V2;      /* 有向边<V1, V2> */
    WeightType Weight;  /* 权重 */
};
typedef struct ENode* Edge;
 
/* 邻接点的定义 */
struct AdjVNode{
    Vertex AdjVertex;        /* 邻接点下标 */
    WeightType Weight;  /* 边权重 */
    AdjVNode* Next;    /* 指向下一个邻接点的指针 */
};
 
/* 顶点表头结点的定义 */
typedef struct Vnode{
    struct AdjVNode* HeadNode;/* 边表头指针 */
    DataType Data;            /* 存顶点的数据 */
    /* 注意：很多情况下，顶点无数据，此时Data可以不用出现 */
} AdjList[MaxVertexNum];    /* AdjList是邻接表类型 */
 
/* 图结点的定义 */
struct GNode{  
    int nVertex;     /* 顶点数 */
    int nEdge;     /* 边数   */
    AdjList GraphAdjList;  /* 邻接表 */
};
typedef struct GNode* LGraph; /* 以邻接表方式存储的图类型 */
 
LGraph CreateGraph( int VertexNum )
{ 
    Vertex V;
    LGraph Graph;
     
    Graph = (LGraph)malloc( sizeof(struct GNode) ); /* 建立图 */
    Graph->nVertex = VertexNum;
    Graph->nEdge= 0;
    /* 初始化邻接表头指针 */
    /* 注意：这里默认顶点编号从0开始，到(Graph->nVertex - 1) */
       for (V=0; V < Graph->nVertex; V++)
          Graph->GraphAdjList[V].HeadNode = NULL;
    return Graph; 
}

vector<int,list< map<int,int> > > graphAdjList(nVertex);

void createGraph_cpp(int VertexNum){
    Vertex V;
    for (V=0; V < VertexNum; V++) {
        Vertex V_ = V+1;
        graphAdjList[V_] = NULL;
    }
}

void buildGraph_cpp() {
    int V1,V2,Weight;
    for (int i=0; i < nEdge; i++) {
        cin >> V1 >> V2 >> Weight;
        graphAdjList[V1].push_back(make_pair(V2,Weight));
    }
}
        
void InsertEdge( LGraph Graph, Edge E )
{
    AdjVNode* NewNode;
    /* 插入边 <V1, V2> */
    /* 为V2建立新的邻接点 */
    NewNode = (AdjVNode* )malloc(sizeof(struct AdjVNode));
    NewNode->AdjVertex= E->V2;
    NewNode->Weight = E->Weight;
    /* 将V2插入V1的表头 */
    NewNode->Next = Graph->GraphAdjList[E->V1].HeadNode;
    Graph->GraphAdjList[E->V1].HeadNode = NewNode;
}
 
LGraph BuildGraph()
{
    LGraph Graph;
    Edge E;
    Vertex V;
    int i;
    cin >> nVertex >> nEdge;
    Graph = CreateGraph(nVertex);
    if ( nEdge != 0 ) {
        E = (Edge)malloc( sizeof(struct ENode) );
        for (i=0; i < nEdge; i++) {
            cin >> E->V1 >> E->V2 >> E->Weight;
            InsertEdge( Graph, E );
        }
    } 
    return Graph;
}

// // DFS  
// void DFS( LGraph Graph, Vertex V, void (*Visit)(Vertex) )
// {   /* 以V为出发点对邻接表存储的图Graph进行DFS搜索 */
//     AdjVNode* W;
//     Visit( V ); /* 访问第V个顶点 */
//     Visited[V] = true; /* 标记V已访问 */
//     /* 对V的每个邻接点W->AdjVertex*/
//     for( W=Graph->GraphAdjList[V].HeadNode; W; W=W->Next ) 
//         if ( !Visited[W->AdjVertex] )    /* 若W->AdjVertex未被访问 */
//             DFS( Graph, W->AdjVertex, Visit );    /* 则递归访问之 */
// }

// BFS
void spfa( LGraph Graph, Vertex V)
{   
    AdjVNode* W;
    queue<Vertex> que;

    for (int i = 0; i < nVertex ; ) {
        dist[++i] = inf;
        Visited[i] = false;
    }
     
 Visited[V] = true; /* 标记V已访问 */
    que.push(V);
    dist[V] = 0;
    while(!que.empty()) {
        Vertex V = que.front();
        que.pop();
        Visited[V] = false;
        /* 对V的每个邻接点W->AdjVertex*/
        for( W=Graph->GraphAdjList[V].HeadNode; W; W=W->Next ) {
            if(dist[W->AdjVertex] > dist[V]+ W->Weight) {
                dist[W->AdjVertex] = dist[V] + W->Weight;
                if(!Visited[W->AdjVertex]) {
                    que.push(W->AdjVertex);
                    Visited[W->AdjVertex] = true;
                }
            }
        }
    }
}

void xmain()
{
    LGraph G = BuildGraph();

    startVertex = 1;

    spfa(G,startVertex);

    for (size_t i = 0; i < nVertex; i++) {
        cout << dist[i+1] << " ";
    }
    cout << endl;
}

int main()
{
    createGraph_cpp(nVertex);
    buildGraph_cpp();
    return 0;
}