#include<stdio.h>
#include<stdlib.h>
#define INF 35000

struct Node
{
    int vertex;
    int weight;
    struct Node* next;
};

struct Graph
{
    int numVertices;
    int *visited;
    struct Node** adj;
};

struct Node* createNode(int v, int weight)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->visited = (int*)malloc(sizeof(int) * vertices);
    graph->adj = (struct Node**)malloc(sizeof(struct Node*) * vertices);

    for(int i = 0; i < vertices; i++)
    {
        graph->adj[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph *graph, int src, int dest, int weight)
{
    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = graph->adj[dest];
    graph->adj[dest] = newNode;
}

void printArr(int dist[], int n, int parent[])
{
    printf("Vertex   Distance from Source              Path\n");
    for (int i = 0; i < n; ++i)
    {
        printf("%d \t\t %d \t\t\t ", i, dist[i]);

        // Print path
        int j = i;
        while (j != -1)
        {
            printf("%d ", j);
            j = parent[j];
            if (j != -1)
                printf("-> ");
        }
        printf("\n");
    }
}

void dijkstra(struct Graph* graph, int start)
{
    int V = graph->numVertices;
    int dist[V];
    int parent[V];

    for (int v = 0; v < V; v++)
    {
        dist[v] = INF;
        parent[v] = -1;
    }

    dist[start] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int minDist = INF;
        int u;

        // Find the vertex with minimum distance value
        for (int v = 0; v < V; v++)
        {
            if (graph->visited[v] == 0 && dist[v] < minDist)
            {
                minDist = dist[v];
                u = v;
            }
        }

        graph->visited[u] = 1;

        struct Node* pCrawl = graph->adj[u];
        while (pCrawl)
        {
            int v = pCrawl->vertex;

            if (graph->visited[v] == 0 && dist[u] != INF && pCrawl->weight + dist[u] < dist[v])
            {
                dist[v] = dist[u] + pCrawl->weight;
                parent[v] = u;
            }
            pCrawl = pCrawl->next;
        }
    }

    printArr(dist, V, parent);
}

int main()
{
    // create the graph given in above figure
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
 
    dijkstra(graph, 0);
 
    return 0;
}
