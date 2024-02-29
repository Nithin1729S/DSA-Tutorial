#include <stdio.h>
#include <stdlib.h>
#define INF 35000

struct Node
{
    int vertex;
    int weight;
    struct Node *next;
};

struct Graph
{
    int numVertices;
    struct Node **adj;
};

struct Node *createNode(int v, int weight)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adj = (struct Node **)malloc(sizeof(struct Node *) * vertices);
    for (int i = 0; i < vertices; i++)
    {
        graph->adj[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest, int weight)
{
    struct Node *newNode = createNode(dest, weight);
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = graph->adj[dest];
    graph->adj[dest] = newNode;
}

void bellmanFord(struct Graph *graph, int src)
{
    int V = graph->numVertices;

    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[src] = 0; // Correct initialization for the source vertex

    // Relax edges repeatedly
    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < V; j++)
        {
            struct Node *current = graph->adj[j];
            while (current)
            {
                int u = j;
                int v = current->vertex;
                int weight = current->weight;

                if (dist[u] != INF && dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                }

                current = current->next;
            }
        }
    }

    // Check for negative cycles
    for (int i = 0; i < V; i++)
    {
        struct Node *current = graph->adj[i];
        while (current)
        {
            int u = i;
            int v = current->vertex;
            int weight = current->weight;

            if (dist[u] != INF && dist[u] + weight < dist[v])
            {
                printf("Graph contains negative weight cycle. Cannot find shortest distances.\n");
                return;
            }

            current = current->next;
        }
    }

    // Print the results
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main()
{
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

    bellmanFord(graph, 0);
    return 0;
}
