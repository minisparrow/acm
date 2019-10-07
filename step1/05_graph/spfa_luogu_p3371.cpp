// https://www.luogu.org/problemnew/solution/P3371

// 题目描述
// 
// 如题，给出一个有向图，请输出从某一点出发到所有点的最短路径长度。
// 
// 输入格式
// 
// 第一行包含三个整数N、M、S，分别表示点的个数、有向边的个数、出发点的编号。
// 
// 接下来M行每行包含三个整数Fi、Gi、Wi，分别表示第i条有向边的出发点、目标点和长度。
// 
// 输出格式
// 
// 一行，包含N个用空格分隔的整数，其中第i个整数表示从点S出发到点i的最短路径长度（若S=i则最短路径长度为0，若从点S无法到达点i，则最短路径长度为2147483647）
// 
// 输入输出样例
// 
// 输入 
// 4 6 1
// 1 2 2
// 2 3 2
// 2 4 1
// 1 3 5
// 3 4 3
// 1 4 4
// 输出  
// 0 2 4 3

#include<bits/stdc++.h>
const long long inf=2147483647;
const int maxn=10005;
const int maxm=500005;

using namespace std;

int nVertex,nEdge,start,num_edge=0;

int dist[maxn],isInqueue[maxn],head[maxm];

struct Edge
{
  int next;
  int to;
  int dist;
} edge[maxm]; //结构体表示静态邻接表

void addedge(int from,int to,int dist) //邻接表建图
{ //以下是数据结构书上的标准代码，不懂翻书看解释
  edge[++num_edge].next = head[from]; //链式存储下一条出边
  edge[num_edge].to = to; //当前节点编号
  edge[num_edge].dist = dist; //本条边的距离
  head[from] = num_edge; //记录下一次的出边情况
}

void spfa()
{
  queue<int> q; //spfa用队列，这里用了STL的标准队列
  for(int i = 1; i <= nVertex; i++) {
    dist[i]=inf; //带权图初始化
    isInqueue[i]=0; //记录点i是否在队列中，同dijkstra算法中的isInqueueited数组
  }
  q.push(start); 
  dist[start]=0; 
  isInqueue[start]=1; //第一个顶点入队，进行标记
  while(!q.empty()) {
    int u=q.front(); //取出队首
    q.pop(); 
    isInqueue[u]=0; //出队标记
    //邻接表遍历，不多解释了（也可用vector代替）
    for(int i = head[u]; i; i = edge[i].next) {
      int v = edge[i].to; 
      //如果有最短路就更改
      if(dist[u] + edge[i].dist < dist[v]) {
        dist[v] = dist[u] + edge[i].dist;
        //未入队则入队
        if(isInqueue[v] == 0) {
          isInqueue[v] = 1; //标记入队
          q.push(v);
        }
      }
    }
  }
}
int main()
{
  cin>> nVertex >> nEdge >> start;
  for(int i = 1; i <= nEdge; i++) {
    int source, end, cost;
    cin >> source >> end >> cost; 
    addedge(source, end, cost); //建图，有向图连一次边就可以了
  }
  spfa(); //开始跑spfa
  for(int i=1; i <= nVertex; i++)
    if(start == i) cout<<0<<" "; //如果是回到自己，直接输出0
      else cout<<dist[i]<<" "; //否则打印最短距离
  return 0;
} //结束