#include<stdio.h>
#include<stdlib.h>
#define INF 35000

struct Node
{
    int vertex;
    int weight;
    struct Node*next;
};

struct Graph
{
    int numVertices;
    int *visited;
    struct Node**adj;
};

struct Node* createNode(int v,int weight)
{
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->vertex=v;
    newNode->weight=weight;
    newNode->next=NULL;
    return newNode;
}

struct Graph*createGraph(int vertices)
{
    struct Graph*graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices=vertices;
    graph->visited=(int*)malloc(sizeof(int)*vertices);
    graph->adj=(struct Node**)malloc(sizeof(struct Node**)*vertices);

    for(int i=0;i<vertices;i++)
    {
        graph->adj[i]=NULL;
        graph->visited[i]=0;
    }

    return graph;
}

void addEdge(struct Graph *graph,int src, int dest,int weight)
{
    struct Node*newNode=createNode(dest,weight);
    newNode->next=graph->adj[src];
    graph->adj[src]=newNode;

    newNode=createNode(src,weight);
    newNode->next=graph->adj[dest];
    graph->adj[dest]=newNode;
}


int isCyclicUtil(struct Graph*graph,int v,int parent)
{
    graph->visited[v]=1;
    
    struct Node*temp=graph->adj[v];

    while(temp)
    {
        int neighbour=temp->vertex;

        if(!graph->visited[neighbour])
        {
            if(isCyclicUtil(graph,neighbour,v)) return 1;
        }
        else if(neighbour!=parent)
        {
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}
int isCyclic(struct Graph*graph)
{
    for(int i=0;i<graph->numVertices;i++)
    {
        if(!graph->visited[i])
        {

        
            if(isCyclicUtil(graph,i,-1))
            {
                return 1;
            }
        }

    }
    return 0;
}

int main() {
    int V = 9;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    if (isCyclic(graph)) {
        printf("Graph contains a cycle.\n");
    } else {
        printf("Graph doesn't contain a cycle.\n");
    }

    return 0;
}