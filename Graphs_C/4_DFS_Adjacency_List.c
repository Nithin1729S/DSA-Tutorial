#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int vertex;
    struct Node *next;
};

struct Graph
{
    int numVertices;
    int *visited;
    struct Node**adjLists;
};

void DFS(struct Graph *graph,int vertex)
{
    struct Node* adjList=graph->adjLists[vertex];
    struct Node*temp=adjList;
    graph->visited[vertex]=1;
    printf("%d ",vertex);
    while(temp)
    {
        int connectedVertex=temp->vertex;
        if(graph->visited[connectedVertex]==0)
        {
            DFS(graph,connectedVertex);
        }
        temp=temp->next;
    }
}

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int *)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest) {
    // from src to dest
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

int main() {
  struct Graph* graph = createGraph(4);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);


  DFS(graph, 2);

  return 0;
}