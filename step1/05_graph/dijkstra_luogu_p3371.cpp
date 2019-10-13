#include<bits/stdc++.h>
using namespace std;
#define maxn 10005
#define maxm 500005
#define INF  1234567890

struct Edge
{   int source,target,cost;
    int next;
} e[maxm];

int head[maxn],cnt,nVertex,nEdge,s,vis[maxn],dis[maxn];

struct node
{
    int w,now;

    //重载运算符把最小的元素放在堆顶（大根堆）
    inline bool operator <(const node &x)const {
        return w > x.w;//这里注意符号要为'>'
    }
};

//优先队列，其实这里一般使用一个pair，但为了方便理解所以用的结构体
priority_queue<node> q;

inline void add(int source,int target,int cost)
{
    //这句话对于此题不需要，但在缩点之类的问题还是有用的
    e[++cnt].source = source;
    e[cnt].target = target;
    e[cnt].cost = cost;
    //存储该点的下一条边
    e[cnt].next = head[source];
    //更新目前该点的最后一条边（就是这一条边）
    head[source] = cnt;
}
//链式前向星加边
void dijkstra()
{
    for(int i=1;i<=nVertex;i++) {
        dis[i]=INF;
    }
    dis[s]=0;
    //赋初值
    q.push((node){0,s});

    //堆为空即为所有点都更新
    while(!q.empty()) {
        node x=q.top();
        q.pop();
        int u=x.now;
        //记录堆顶（堆内最小的边）并将其弹出
        if(vis[u]) continue; 
        //没有遍历过才需要遍历
        vis[u]=1;
        //搜索堆顶所有连边
        for(int i=head[u];i;i=e[i].next) {
            int v=e[i].target;
            if(dis[v]>dis[u]+e[i].cost) {
                //松弛操作
                dis[v]=dis[u]+e[i].cost;
                //把新遍历到的点加入堆中
                q.push((node){dis[v],v});
            }
        }
    }
}
int main()
{
    cin >> nVertex >> nEdge >> s;
    for(int i=1,x,y,z; i<= nEdge ;i++)
    {
        cin >> x >> y >> z;
        add(x,y,z);
    }
    dijkstra();
    for(int i=1;i <= nVertex;i++) {
        printf("%d ",dis[i]);
    }
    return 0;
}