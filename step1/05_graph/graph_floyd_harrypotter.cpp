#include <iostream>
#include <climits>
#include <stdlib.h>
//  6 11 6个顶点，11条边
//  3 4 70 
//  1 2 1 
//  5 4 50 
//  2 6 50 
//  5 6 60 
//  1 3 70
//  4 6 60
//  3 6 80
//  5 1 100
//  2 4 60
//  5 2 80
using namespace std;

#define nMaxVertex 1000
#define INFINITY 65535 //double word maximum

typedef int Vertex;
typedef int WeightType;

struct Edge{
    Vertex v1,v2;
    WeightType weight;
};
typedef Edge* ptrEdge;

struct GraphNode{
    int nVertex;
    int nEdge;
    WeightType GMat[nMaxVertex][nMaxVertex];
};

typedef GraphNode* MGraph;

MGraph createGraph(int nVertex)
{
    Vertex v, w;
    MGraph graph;
    graph = (MGraph)malloc(sizeof(struct GraphNode));
    graph->nVertex = nVertex;
    graph->nEdge = 0;
    for(v = 0; v < graph->nVertex; v++) {
        for(w = 0; w < graph->nVertex; w++) {
            graph->GMat[v][w] = INFINITY;
        }
    }
    return graph;
}

void InsertEdge(MGraph graph, ptrEdge edge){
    graph->GMat[edge->v1][edge->v2] = edge->weight;
    graph->GMat[edge->v2][edge->v1] = edge->weight;
}

MGraph BuildGraph()
{
    int nVertex,nEdge;
    cin >>  nVertex >> nEdge;
    MGraph graph;
    ptrEdge edge;

    graph = createGraph(nVertex);
    for(int i = 0; i < nEdge; i++) {
        edge = (ptrEdge)malloc(sizeof(struct Edge));
        cin >> edge->v1 >> edge->v2 >> edge->weight;
        edge->v1--;
        edge->v2--;
        InsertEdge(graph,edge);
    }
    return graph;
}

void Floyd(MGraph graph,WeightType D[nMaxVertex][nMaxVertex]) {
    Vertex i,j,k;
    for (i = 0; i < graph->nVertex; i++) {
        for (j = 0; j < graph->nVertex; j++) {
            D[i][j] = graph->GMat[i][j];
        }
    }

    for(k = 0; k < graph->nVertex; k++) {
        for(i = 0; i < graph->nVertex; i++) {
            for(j = 0; j < graph->nVertex; j++) {
                if (D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    // if (i == j && D[i][j] < 0) { //负数圈
                    //     return false;
                    // }
                }
            }
        }
    }
    for (i = 0; i < graph->nVertex; i++) {
        for (j = 0; j < graph->nVertex; j++) {
            cout << D[i][j] << " ";
        }
        cout << endl;
    }
}

WeightType FindMaxDist(WeightType D[][nMaxVertex], Vertex i, int N) {
    WeightType maxDist = 0;
    for(Vertex j = 0; j < N; j++) {
        if (i != j && D[i][j] > maxDist) {
            maxDist = D[i][j];
        }
    }
    return maxDist;
}

void FindAnimal(MGraph graph) {
    WeightType D[nMaxVertex][nMaxVertex];
    WeightType maxDist;
    WeightType minDist = INFINITY;
    int Animal; 
    Floyd(graph,D);
    for(Vertex i = 0; i < graph->nVertex; i++) {
        maxDist = FindMaxDist(D,i,graph->nVertex);
        if (maxDist < minDist) {
            minDist = maxDist;
            Animal = i + 1;
        }
        if (minDist == INFINITY) {
            cout << "No solution. " << endl;
            return;
        }
    }
    cout << "Animal: " << Animal << " minDist: "  << minDist << endl;
}

int main()
{
    //insert edge to Edge
    MGraph graph;
    graph = BuildGraph();
    FindAnimal(graph);
    return 0;

}